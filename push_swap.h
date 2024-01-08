/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:57:48 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/08 01:19:52 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "stdlib.h"

typedef struct s_stack{
	t_list	*head;
	t_list	*tail;
	int		size;
	char	*name;
}			t_stack;

typedef struct s_vec2
{
	int	x;
	int	y;
}		t_vec2;

typedef struct s_move
{
	int	from;
	int	to;
	int	rot;
	int	n_of_moves;
}		t_move;

void	clean_exit(const int i);
t_stack	*get_b(void);
t_stack	*get_a(void);

t_stack	*load_a(int argc, char **argv);

void	print_stack(t_stack *a);
void	stack_add_back(t_stack *a, int i);

void swap(t_stack *s);
void	sa(void);
void	sb(void);
void	ss(void);

void	push(t_stack *a, t_stack *b);
void	pa();
void	pb();

void	stack_rotate(t_stack *s);
void	rb();
void	ra();
void	rr();

void	stack_rrotate(t_stack *s);
void	rrb();
void	rra();
void	rrr();

#endif // !PUSH_SWAP_H
