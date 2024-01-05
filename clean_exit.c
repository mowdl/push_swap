/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:56 by mel-meka          #+#    #+#             */
/*   Updated: 2024/01/04 13:56:25 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_with_free(void *content)
{
	free(content);
}

void	clean_exit(const int i)
{
	ft_lstclear(&get_a()->head, del_with_free);
	ft_lstclear(&get_b()->head, del_with_free);
	if (i)
	{
		ft_printf("Error\n");
		exit(i);
	}
	exit(0);
}
