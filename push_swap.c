/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:59:00 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/08 21:58:52 by mel-meka         ###   ########.fr       */
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
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (0);
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
	s = 0;
	i = 1;
	while (i < 4)
	{
		if (ops[i] < ops[s])
			s = i;
		i++;
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
	t_move move;

	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	move.n_of_moves = 2147483647;
	i = 0;
	while (i < a->size)
	{
		i_of_smaller = get_i_of_biggest_smaller_than(b, get_v_at_i(a, i));
		n_of_moves = best_rotation_scenario(a, b, i,  i_of_smaller).y + 1;
		if (n_of_moves < move.n_of_moves)
		{
			move.from = i;
			move.to = i_of_smaller;
			move.rot = best_rotation_scenario(a, b, i,  i_of_smaller).x;
			move.n_of_moves = n_of_moves;
		}
	}
	return (move);
}

void	exe_move(t_move move)
{

	if (move.rot == 0)
	{
		while (move.from > 0 && move.to > 0)
		{
			rr();
			move.from--;
			move.to--;
		}
		while (move.from)
		{
			ra();
			move.from--;
		}
		while (move.to)
		{
			rb();
			move.to--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_a(argc, argv);
	b = get_b();
	pb();
	pb();
	print_stack(a);
	print_stack(b);
}
