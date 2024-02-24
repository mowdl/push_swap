/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:35:58 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:34:42 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_stack(t_stack *a)
{
	t_list	*tmp;

	tmp = a->head;
	if (tmp == NULL)
		ft_printf("%s: stack is empty\n", a->name);
	while (tmp)
	{
		ft_printf("%i    ", *(int *)tmp->content);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	ft_printf("  size: %i\n", a->size);
}

void	check_unique(t_stack *s, int v)
{
	t_list	*tmp;

	tmp = s->head;
	while (tmp)
	{
		if (*(int *)tmp->content == v)
			clean_exit(1);
		tmp = tmp->next;
	}
}

void	stack_add_back(t_stack *a, int i)
{
	int		*v;
	t_list	*node;

	check_unique(a, i);
	v = malloc(sizeof(int));
	if (v == NULL)
		clean_exit(1);
	*v = i;
	node = ft_lstnew(v);
	if (node == NULL)
	{
		free(v);
		clean_exit(1);
	}
	if (a->head == NULL)
	{
		a->head = node;
		a->tail = node;
		return ;
	}
	a->tail->next = node;
	a->tail = node;
}
