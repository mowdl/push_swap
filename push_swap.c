/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:59:00 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/23 07:10:28 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_a(void)
{
	static t_stack	a;
	if (a.name == NULL)
		a.name = "a";
	return (&a);
}

t_stack	*get_b(void)
{
	static t_stack	b;
	if (b.name == NULL)
		b.name = "b";
	return (&b);
}



int	get_i_of_biggest_smaller_than(t_stack *b, int v)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	i = 0;
	tmp = b->head;
	prev = b->tail;
	while (tmp)
	{
		if (*(int*)tmp->content < v)
		{
			if (*(int*)prev->content < *(int*)tmp->content)
				return (i);
			if (*(int*)prev->content > v)
				return (i);
		}
		if (*(int *)prev->content < *(int *)tmp->content)
		{
			if (v < *(int*)prev->content)
				return (i);
		}
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	get_v_at_i(t_stack *s, int i)
{
	t_list	*tmp;

	tmp = s->head;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	return (*(int*)tmp->content);
}

int	max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int	min(int a, int b)
{
	if (a < b)
		return a;
	return (b);
}

t_vec2	best_rotation_scenario(t_stack *a, t_stack *b, int ia, int ib)
{
	int	ops[4];
	int	i;
	int	s;
	t_vec2 r;

	ops[0] = max(ia, ib);
	ops[1] = max(a->size - ia, b->size - ib);
	ops[2] = ia + (b->size - ib);
	ops[3] = ib + (a->size - ia);
	s = 3;
	i = 2;
	while (i >= 0)
	{
		if (ops[i] < ops[s])
			s = i;
		i--;
	}
	r.x = s;
	r.y = ops[s];
	return (r);
}

t_move	i_of_cheapest_to_move(t_stack *a, t_stack *b)
{
	int	i_of_smaller;
	int	i;
	int	n_of_moves;
	int	v;
	t_move move;

	move.n_of_moves = -1;
	i = 0;
	while (i < a->size)
	{
		v = get_v_at_i(a, i);
		i_of_smaller = get_i_of_biggest_smaller_than(b, v);
		n_of_moves = best_rotation_scenario(a, b, i,  i_of_smaller).y + 1;
		if (n_of_moves < move.n_of_moves || move.n_of_moves == -1)
		{
			move.from = i;
			move.to = i_of_smaller;
			move.rot = best_rotation_scenario(a, b, i,  i_of_smaller).x;
			move.n_of_moves = n_of_moves;
		}
		i++;
	}
	return (move);
}

void	sort_in_b(t_stack *a, t_stack *b)
{
	t_move	move;

	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	while (a->size)
	{
		move = i_of_cheapest_to_move(a, b);
		exe_move(move);
	}
}

void	smallest_to_top(t_stack *a)
{
	int	i_min;
	int v_min;
	int	i;
	t_list	*tmp;

	tmp = a->head->next;
	i = 0;
	i_min = 0;
	v_min = *(int*)a->head->content;
	while (tmp)
	{
		i++;
		if (v_min > *(int *)tmp->content)
		{
			i_min = i;
			v_min = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	a->size = ft_lstsize(a->head);
	while (i_min != 0 && i_min != a->size)
	{
		if (i_min <= a->size / 2)
		{
			ra();
			i_min--;
		}
		else 
		{
			rra();
			i_min++;
		}
	}
}

void	push_b_to_a(t_stack *b)
{
	int		i;
	t_list	*tmp;

	tmp = b->head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (i)
	{
		pa();
		i--;
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	pb();
	pb();
	sort_in_b(a, b);
	push_b_to_a(b);
	smallest_to_top(a);
}

int	is_stack_sorted(t_stack *a)
{
	t_list	*tmp;

	tmp = a->head;
	while (tmp->next)
	{
		if (*(int*)tmp->content > *(int*)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


void	sort_3_stack(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	if (is_stack_sorted(a))
		return ;
	a1 = *(int *)a->head->content;
	a2 = *(int *)a->head->next->content;
	a3 = *(int *)a->tail->content;
	if (a1 > a2 && a1 < a3 && a2 < a3)
		sa();
	else if (a1 < a2 && a1 > a3 && a2 > a3)
		rra();
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		ra();
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		ra();
		sa();
	}
	else
	{
		rra();
		sa();
	}
}

void	sort_4_stack(t_stack *a)
{
	int	bv;

	pb();
	bv = *(int *)get_b()->head->content;
	sort_3_stack(a);
	if(bv < *(int *)a->head->content)
		pa();
	else if (bv < *(int *)a->head->next->content)
	{
		ra();
		pa();
		rra();
	}
	else if (bv < *(int *)a->head->next->next->content)
	{
		rra();
		pa();
		ra();
		ra();
	}
	else
	{
		pa();
		ra();
	}
}

void	sort_5_stack(t_stack *a)
{
	int	bv;

	pb();
	sort_4_stack(a);
	bv = *(int *)get_b()->head->content;
	if(bv < *(int *)a->head->content)
		pa();
	else if (bv < *(int *)a->head->next->content)
	{
		ra();
		pa();
		rra();
	}
	else if (bv < *(int *)a->head->next->next->content)
	{
		ra();
		ra();
		pa();
		rra();
		rra();
	}
	else if (bv < *(int *)a->head->next->next->next->content)
	{
		rra();
		pa();
		ra();
		ra();
	}
	else
	{
		pa();
		ra();
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_a(argc, argv);
	b = get_b();
	a->size = ft_lstsize(a->head);
	if (is_stack_sorted(a))
		clean_exit(0);
	else if (a->size == 2)
		ra();
	else if (a->size == 3)
		sort_3_stack(a);
	else if (a->size == 4)
		sort_4_stack(a);
	else if (a->size == 5)
		sort_5_stack(a);
	else
		sort_big_stack(a, b);
	clean_exit(0);
}
