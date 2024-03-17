/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:36:22 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/17 20:36:35 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin_space(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, " ");
	free(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = ft_strjoin(str, str2);
	free(str);
	return (tmp);
}

char	**split_and_join(int argc, char **argv)
{
	static char	**arr;
	char		*str;
	char		*tmp;
	int			i;

	tmp = ft_strdup(argv[1]);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	i = 2;
	while (i < argc)
	{
		tmp = strjoin_space(str, argv[i]);
		if (tmp == NULL)
			return (NULL);
		str = tmp;
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	return (arr);
}

char	***get_arr(void)
{
	static char	**arr;

	return (&arr);
}
