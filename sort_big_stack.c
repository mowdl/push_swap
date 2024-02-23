/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:03:29 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:14:16 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_smallest_i(t_stack *a)
{
	int		i_min;
	int		v_min;
	int		i;
	t_list	*tmp;

	tmp = a->head->next;
	i = 0;
	i_min = 0;
	v_min = *(int *)a->head->content;
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
	return (i_min);
}

void	smallest_to_top(t_stack *a)
{
	int	i_min;

	i_min = get_smallest_i(a);
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
