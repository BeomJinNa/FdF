/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:00:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "s_map.h"

static int	wrong_args(void);
static int	open_error(void);
static int	parsing_error(void);

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac != 2)
		return (wrong_args());
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (open_error());
	parse_the_map_file(&map, fd);
	if (map == NULL)
		return (parsing_error());
	close(fd);
	return (0);
}

static int	wrong_args(void)
{
	ft_printf("Usage: ./fdf <file name>\n");
	return (0);
}

static int	open_error(void)
{
	perror("Error opening file");
	return (1);
}

static int	parsing_error(void)
{
	perror("Error loading map");
	return (1);
}
