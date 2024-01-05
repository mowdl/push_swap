/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:43 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/05 00:33:46 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (*str && ft_isdigit(*str))
	{
		digits++;
		if (digits > 10)
			break;
		r = r * 10 + (*str - '0');
		str++;
	}
	r = r * s;
	if ((*str != '\0' && !ft_isdigit(*str))
		|| digits > 10 || r > (long)2147483647 || r < (long)-2147483648)
		clean_exit(1);
	return (r);
}

t_stack	*load_a(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	char	**args;

	a = get_a();
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		stack_add_back(a, stack_atoi(argv[i]));
		i++;
	}
	return (a);
}
