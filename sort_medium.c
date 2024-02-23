/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:41:39 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/23 23:42:06 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_stack(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	if (is_stack_sorted(a))
		return ;
	a1 = *(int *)a->head->content;
	a2 = *(int *)a->head->next->content;
	a3 = *(int *)a->tail->content;
	if (a1 > a2 && a1 < a3 && a2 < a3)
		sa();
	else if (a1 < a2 && a1 > a3 && a2 > a3)
		rra();
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		ra();
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		ra();
		sa();
	}
	else
	{
		rra();
		sa();
	}
}

void	sort_4_stack(t_stack *a)
{
	int	bv;

	pb();
	bv = *(int *)get_b()->head->content;
	sort_3_stack(a);
	if (bv < *(int *)a->head->content)
		pa();
	else if (bv < *(int *)a->head->next->content)
	{
		ra();
		pa();
		rra();
	}
	else if (bv < *(int *)a->head->next->next->content)
	{
		rra();
		pa();
		ra();
		ra();
	}
	else
	{
		pa();
		ra();
	}
}

void	pa_to_i_2(void)
{
	ra();
	ra();
	pa();
	rra();
	rra();
}

void	pa_to_i_1(void)
{
	ra();
	pa();
	rra();
}

void	sort_5_stack(t_stack *a)
{
	int	bv;

	pb();
	sort_4_stack(a);
	bv = *(int *)get_b()->head->content;
	if (bv < *(int *)a->head->content)
		pa();
	else if (bv < *(int *)a->head->next->content)
		pa_to_i_1();
	else if (bv < *(int *)a->head->next->next->content)
		pa_to_i_2();
	else if (bv < *(int *)a->head->next->next->next->content)
	{
		rra();
		pa();
		ra();
		ra();
	}
	else
	{
		pa();
		ra();
	}
}
