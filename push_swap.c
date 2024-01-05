/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:59:00 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/04 23:20:20 by mel-meka         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_a(argc, argv);
	b = get_b();
	//print_stack(a);
	//print_stack(b);
	int l = 1;
	while (l)
	{
		l = 0;
		while (a->head && a->head->next)
		{
			if (*(int*)a->head->content > *(int*)a->head->next->content)
			{
				sa();
				l = 1;
			}
			pb();
		}
		pb();
		while (b->head && b->head->next)
		{
			if (*(int*)b->head->content < *(int*)b->head->next->content)
			{
				sb();
				l = 1;
			}
			pa();
		}
		pa();
	}
	//print_stack(a);
	//print_stack(b);
}
