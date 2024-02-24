/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:08:56 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:07:50 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_list	*tmp;
	t_list	*third;

	if (s->head == NULL || s->head->next == NULL)
		Error() ;
	tmp = s->head;
	third = s->head->next->next;
	s->head = s->head->next;
	s->head->next = tmp;
	tmp->next = third;
	if (third == NULL)
		s->tail = s->head->next;
}

void	sa(void)
{
	swap(get_a());
}

void	sb(void)
{
	swap(get_b());
}

void	ss(void)
{
	swap(get_b());
	swap(get_a());
}
