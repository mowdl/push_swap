/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rrotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:12:52 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:34:42 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stack_rrotate(t_stack *s)
{
	t_list	*tmp;

	if (s->head == NULL || s->head->next == NULL)
		Error();
	tmp = s->head;
	while (tmp->next->next)
		tmp = tmp->next;
	s->tail = tmp;
	tmp = tmp->next;
	s->tail->next = NULL;
	ft_lstadd_front(&s->head, tmp);
}

void	rra(void)
{
	stack_rrotate(get_a());
}

void	rrb(void)
{
	stack_rrotate(get_b());
}

void	rrr(void)
{
	stack_rrotate(get_a());
	stack_rrotate(get_b());
}
