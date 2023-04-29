/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 11:03:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "s_map.h"

void		parse_the_map_file(t_map *map, int fd);
static int	wrong_args(void);
static int	open_error(void);
static int	parsing_error(void);
static void	release_points(t_point **point);

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
	close(fd);
	if (map.point == NULL)
		return (parsing_error());
	release_points(map.point);
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
	ft_putstr_fd("Error loading map\n", 2);
	return (1);
}

static void	release_points(t_point **point)
{
	t_point	**ptr;

	if (point == NULL)
		return ;
	ptr = point;
	while (*ptr != NULL)
		free(*ptr++);
	free(point);
}
