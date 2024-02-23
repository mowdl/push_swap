/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_to_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:54:39 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:00:47 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*(int *)tmp->content < v)
		{
			if (*(int *)prev->content < *(int *)tmp->content)
				return (i);
			if (*(int *)prev->content > v)
				return (i);
		}
		if (*(int *)prev->content < *(int *)tmp->content)
			if (v < *(int *)prev->content)
				return (i);
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
	return (*(int *)tmp->content);
}

t_vec2	best_rotation_scenario(t_stack *a, t_stack *b, int ia, int ib)
{
	int		ops[4];
	int		i;
	int		s;
	t_vec2	r;

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
	int		i_of_smaller;
	int		i;
	int		n_of_moves;
	int		v;
	t_move	move;

	move.n_of_moves = -1;
	i = 0;
	while (i < a->size)
	{
		v = get_v_at_i(a, i);
		i_of_smaller = get_i_of_biggest_smaller_than(b, v);
		n_of_moves = best_rotation_scenario(a, b, i, i_of_smaller).y + 1;
		if (n_of_moves < move.n_of_moves || move.n_of_moves == -1)
		{
			move.from = i;
			move.to = i_of_smaller;
			move.rot = best_rotation_scenario(a, b, i, i_of_smaller).x;
			move.n_of_moves = n_of_moves;
		}
		i++;
	}
	return (move);
}
