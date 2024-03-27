/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:43 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/17 20:37:21 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*str == '\0')
			clean_exit(1);
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

t_stack	*load_a(int argc, char **argv)
{
	t_stack	*a;
	char	**arr;

	a = get_a();
	if (argc < 2)
		clean_exit(1);
	*get_arr() = split_and_join(argc, argv);
	arr = *get_arr();
	if (arr == NULL)
		clean_exit(1);
	while (*arr != NULL)
	{
		stack_add_back(a, stack_atoi(*arr));
		arr++;
	}
	free_arr(*get_arr());
	*get_arr() = NULL;
	return (a);
}
