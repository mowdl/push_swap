/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:04:51 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/09 00:19:08 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_ra_rb(t_move move)
{
	while (move.from && move.to)
	{
		rr();
		move.from--;
		move.to--;
	}
	while (move.from)
	{
		ra();
		move.from--;
	}
	while (move.to)
	{
		rb();
		move.to--;
	}
}

void	rrr_rra_rrb(t_move move)
{
	int	a_size;
	int	b_size;

	a_size = get_a()->size;
	b_size = get_b()->size;
	while (move.from != a_size && move.to != b_size)
	{
		rrr();
		move.from++;
		move.to++;
	}
	while (move.from < a_size)
	{
		rra();
		move.from++;
	}
	while (move.to < b_size)
	{
		rrb();
		move.to++;
	}
}

void	ra_rrb(t_move move)
{
	while (move.from)
	{
		ra();
		move.from--;
	}
	while (move.to != get_b()->size)
	{
		rrb();
		move.to++;
	}
}

void	rra_rb(t_move move)
{
	while (move.to)
	{
		rb();
		move.to--;
	}
	while (move.from != get_a()->size)
	{
		rra();
		move.from++;
	}
}

void	exe_move(t_move move)
{
	ft_printf("---Iteration: rot: %i from: %i to: %i n: %i\n", move.rot, move.from, move.to, move.n_of_moves);
	if (move.rot == 0)
		rr_ra_rb(move);
	else if (move.rot == 1)
		rrr_rra_rrb(move);
	else if (move.rot == 2)
		ra_rrb(move);
	else if (move.rot == 3)
		rra_rb(move);
	pb();
	get_a()->size--;
	get_b()->size++;
}
