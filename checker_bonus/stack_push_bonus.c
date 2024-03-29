/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:43:05 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:52:29 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	if (b->head == NULL)
		b->tail = NULL;
	ft_lstadd_front(&a->head, tmp);
	if (a->tail == NULL)
		a->tail = a->head;
}

void	pa(void)
{
	push(get_a(), get_b());
}

void	pb(void)
{
	push(get_b(), get_a());
}
