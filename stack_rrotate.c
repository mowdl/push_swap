/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:12:52 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:19:38 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rrotate(t_stack *s)
{
	t_list	*tmp;

	if (s->head == NULL || s->head->next == NULL)
		return ;
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
	ft_printf("rra\n");
}

void	rrb(void)
{
	stack_rrotate(get_b());
	ft_printf("rrb\n");
}

void	rrr(void)
{
	stack_rrotate(get_a());
	stack_rrotate(get_b());
	ft_printf("rrr\n");
}
