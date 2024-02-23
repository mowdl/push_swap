/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:59:00 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:04:21 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_a(void)
{
	static t_stack	a;

	if (a.name == NULL)
		a.name = "a";
	return (&a);
}

t_stack	*get_b(void)
{
	static t_stack	b;

	if (b.name == NULL)
		b.name = "b";
	return (&b);
}

int	is_stack_sorted(t_stack *a)
{
	t_list	*tmp;

	tmp = a->head;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_a(argc, argv);
	b = get_b();
	a->size = ft_lstsize(a->head);
	if (is_stack_sorted(a))
		clean_exit(0);
	else if (a->size == 2)
		ra();
	else if (a->size == 3)
		sort_3_stack(a);
	else if (a->size == 4)
		sort_4_stack(a);
	else if (a->size == 5)
		sort_5_stack(a);
	else
		sort_big_stack(a, b);
	clean_exit(0);
}
