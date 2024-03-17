/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:43:45 by mel-meka          #+#    #+#             */
/*   Updated: 2024/03/17 21:43:45 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
