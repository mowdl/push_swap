/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:41:12 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:34:42 by mel-meka         ###   ########.fr       */
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

void print_node(void *line)
{
	ft_printf("checker: %s", (char *)line);
}

void print_ops()
{
	ft_lstiter(*get_ops(), print_node);
}
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
	Error();
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
		Error();
}

void	execute_ops()
{
	t_list	*node;

	node = *get_ops();
	while (node)
	{
		execute_op(node->content);
		node = node->next;
	}
	if (ft_lstsize(get_b()->head) != 0)
		KO();
	if (!is_stack_sorted(get_a()))
		KO();
}

void load_ops(void)
{
	char	*line;
	t_list	*node;

	line = get_next_line(0);
	while (line)
	{
		check_line(line);
		node = ft_lstnew(line);
		if (node == NULL)
			Error();
		ft_lstadd_back(get_ops(), node);
		line = get_next_line(0);
	}
}



int	main(int argc, char **argv)
{
	load_a(argc, argv);
	load_ops();
	execute_ops();
	OK();
}

