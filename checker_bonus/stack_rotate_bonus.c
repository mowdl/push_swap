/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:58:29 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/25 02:07:51 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stack_rotate(t_stack *s)
{
	t_list	*tmp;

	if (s->head == NULL || s->head->next == NULL)
		return ;
	tmp = s->head;
	s->head = s->head->next;
	s->tail->next = tmp;
	s->tail = tmp;
	tmp->next = NULL;
}

void	ra(void)
{
	stack_rotate(get_a());
}

void	rb(void)
{
	stack_rotate(get_b());
}

void	rr(void)
{
	stack_rotate(get_a());
	stack_rotate(get_b());
}
