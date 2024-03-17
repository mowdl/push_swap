/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:56 by mel-meka          #+#    #+#             */
/*   Updated: 2024/02/25 02:32:22 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	del_with_free(void *content)
{
	free(content);
}

void	free_arr(char **arr)
{
	char	**tmp;

	if (arr == NULL)
		return ;
	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

void	clean_exit(const int i)
{
	ft_lstclear(&get_a()->head, del_with_free);
	ft_lstclear(&get_b()->head, del_with_free);
	free_arr(*get_arr());
	if (i)
	{
		ft_printf("Error\n");
		exit(i);
	}
	exit(0);
}
