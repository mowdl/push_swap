/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:56 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/17 20:31:51 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (write(2, "Error\n", 6))
			exit(i);
	}
	exit(0);
}
