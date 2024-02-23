/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:58:29 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:19:14 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("ra\n");
}

void	rb(void)
{
	stack_rotate(get_b());
	ft_printf("rb\n");
}

void	rr(void)
{
	stack_rotate(get_a());
	stack_rotate(get_b());
	ft_printf("rr\n");
}
