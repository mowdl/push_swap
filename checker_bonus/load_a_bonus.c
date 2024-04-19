/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:44:43 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/24 23:34:42 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	stack_atoi(const char *str)
{
	long	r;
	int		s;

	s = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
		if (*str == '\0')
			clean_exit(1);
	}
	r = 0;
	while (*str && ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		if ((r * s) > 2147483647 || (r * s < -2147483648))
			clean_exit(1);
		str++;
	}
	r = r * s;
	if (*str != '\0' && !ft_isdigit(*str))
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
