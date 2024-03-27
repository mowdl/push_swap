/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:14:23 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/27 02:14:23 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value(t_list *head)
{
	return (*(int *)head->content);
}

int	find_place_in_a(t_stack *a, t_stack *b)
{
	int		i;
	t_list	*a_ele;
	t_list	*a_prev;

	a_ele = a->head;
	a_prev = a->tail;
	i = 0;
	while (a_ele)
	{
		if (value(a_ele) > value(a_prev))
		{
			if (value(b->head) > value(a_prev) && value(b->head) < value(a_ele))
				return (i);
		}
		else if (value(b->head) < value(a_ele)
			|| value(b->head) > value(a_prev))
			return (i);
		a_prev = a_ele;
		a_ele = a_ele->next;
		i++;
	}
	return (i);
}

void	move_top_b_to(t_stack *a, t_stack *b, int i)
{
	if (i <= a->size / 2)
		while (i--)
			ra();
	else
		while (i++ < a->size)
			rra();
	pa();
	a->size++;
	b->size--;
}

void	sort_in_a(t_stack *a, t_stack *b)
{
	int	i_to_move_to;

	b->size = ft_lstsize(b->head);
	a->size = ft_lstsize(a->head);
	while (b->size > 0)
	{
		i_to_move_to = find_place_in_a(a, b);
		move_top_b_to(a, b, i_to_move_to);
	}
}
