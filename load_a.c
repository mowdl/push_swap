/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:43 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 00:11:19 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	stack_atoi_loop(const char **str, int *digits, long *r)
{
	while (**str && ft_isdigit(**str))
	{
		(*digits)++;
		if (*digits > 10)
			break ;
		*r = *r * 10 + (**str - '0');
		(*str)++;
	}
}

int	stack_atoi(const char *str)
{
	long	r;
	int		s;
	int		digits;

	s = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	digits = 0;
	r = 0;
	stack_atoi_loop(&str, &digits, &r);
	r = r * s;
	if ((*str != '\0' && !ft_isdigit(*str))
		|| digits > 10 || r > (long)2147483647 || r < (long)-2147483648)
		clean_exit(1);
	return (r);
}

void	load_with_split(t_stack *a, char *arg)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, ' ');
	if (args == NULL)
		clean_exit(1);
	while (args[i])
	{
		stack_add_back(a, stack_atoi(args[i]));
		i++;
	}
	free_arr(args);
}

t_stack	*load_a(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = get_a();
	if (argc < 2)
		clean_exit(1);
	if (argc == 2)
	{
		load_with_split(a, argv[1]);
		return (a);
	}
	i = 1;
	while (i < argc)
	{
		stack_add_back(a, stack_atoi(argv[i]));
		i++;
	}
	return (a);
}
