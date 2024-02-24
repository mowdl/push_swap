/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:46:30 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 03:15:17 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "stdlib.h"

typedef struct s_stack{
	t_list	*head;
	t_list	*tail;
	int		size;
	char	*name;
}			t_stack;


t_stack	*get_a(void);
t_stack	*get_b(void);

t_stack	*load_a(int argc, char **argv);

void	clean_exit(const int i);
void	Error(void);
void	KO(void);
void	OK(void);

void	print_stack(t_stack *a);
void	stack_add_back(t_stack *a, int i);

void	swap(t_stack *s);
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


#endif
