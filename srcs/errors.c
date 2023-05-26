/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:32:07 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:42:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	wrong_args(void)
{
	ft_printf(
		"Usage: ./fdf <file name> [<window width size> <window height size>]\n");
	return (0);
}

int	open_error(void)
{
	perror("Error opening file");
	return (1);
}

int	parsing_error(void)
{
	ft_putstr_fd("Error loading map\n", 2);
	return (1);
}
