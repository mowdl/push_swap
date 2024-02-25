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

void	clean_exit(const int i)
{
	ft_lstclear(&get_a()->head, del_with_free);
	ft_lstclear(&get_b()->head, del_with_free);
	ft_lstclear(get_ops(), del_with_free);
	if (i)
	{
		write(2, "Error\n", 6);
		exit(i);
	}
	exit(0);
}

void	checker_error(void)
{
	clean_exit(1);
}

void	ko(void)
{
	ft_printf("KO\n");
	clean_exit(0);
}

void	ok(void)
{
	ft_printf("OK\n");
	clean_exit(0);
}
