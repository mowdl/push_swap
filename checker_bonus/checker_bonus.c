/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:41:12 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/25 02:33:40 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

t_list	**get_ops(void)
{
	static t_list	*ops;

	return (&ops);
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
	if (argc == 1)
		return (0);
	load_a(argc, argv);
	load_ops();
	execute_ops();
	if (ft_lstsize(get_b()->head) != 0)
		ko();
	if (!is_stack_sorted(get_a()))
		ko();
	ok();
}
