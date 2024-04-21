/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:23:35 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/29 01:32:42 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	check_line(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return ;
	else if (!ft_strcmp(line, "sb\n"))
		return ;
	else if (!ft_strcmp(line, "ss\n"))
		return ;
	else if (!ft_strcmp(line, "pa\n"))
		return ;
	else if (!ft_strcmp(line, "pb\n"))
		return ;
	else if (!ft_strcmp(line, "ra\n"))
		return ;
	else if (!ft_strcmp(line, "rb\n"))
		return ;
	else if (!ft_strcmp(line, "rr\n"))
		return ;
	else if (!ft_strcmp(line, "rra\n"))
		return ;
	else if (!ft_strcmp(line, "rrb\n"))
		return ;
	else if (!ft_strcmp(line, "rrr\n"))
		return ;
	free(line);
	checker_error();
}

void	load_ops(void)
{
	char	*line;
	t_list	*node;

	line = get_next_line(0);
	while (line)
	{
		check_line(line);
		node = ft_lstnew(line);
		if (node == NULL)
			checker_error();
		ft_lstadd_back(get_ops(), node);
		line = get_next_line(0);
	}
}

void	execute_op(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa();
	else if (!ft_strcmp(line, "sb\n"))
		sb();
	else if (!ft_strcmp(line, "ss\n"))
		ss();
	else if (!ft_strcmp(line, "pa\n"))
		pa();
	else if (!ft_strcmp(line, "pb\n"))
		pb();
	else if (!ft_strcmp(line, "ra\n"))
		ra();
	else if (!ft_strcmp(line, "rb\n"))
		rb();
	else if (!ft_strcmp(line, "rr\n"))
		rr();
	else if (!ft_strcmp(line, "rra\n"))
		rra();
	else if (!ft_strcmp(line, "rrb\n"))
		rrb();
	else if (!ft_strcmp(line, "rrr\n"))
		rrr();
	else
		checker_error();
}

void	execute_ops(void)
{
	t_list	*node;

	node = *get_ops();
	while (node)
	{
		execute_op(node->content);
		node = node->next;
	}
}
