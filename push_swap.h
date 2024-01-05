/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:57:48 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/04 19:21:30 by mel-meka         ###   ########.fr       */
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
	char	*name;
}			t_stack;

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
