/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 04:05:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "s_map.h"
#include "mlx.h"

void		parse_the_map_file(t_map *map, int fd);
void		run_mlx(t_status *stat);
void		release_points(t_point **point);
static int	wrong_args(void);
static int	open_error(void);
static int	parsing_error(void);

int	main(int ac, char **av)
{
	int			fd;
	t_status	stat;

	if (ac != 2)
		return (wrong_args());
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (open_error());
	parse_the_map_file(&stat.map, fd);
	close(fd);
	if (stat.map.point == NULL)
		return (parsing_error());
	stat.filename = av[1];
	stat.win_width = 1920;
	stat.win_height = 1080;
	run_mlx(&stat);
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

void	release_points(t_point **point)
{
	t_point	**ptr;

	if (point == NULL)
		return ;
	ptr = point;
	while (*ptr != NULL)
		free(*ptr++);
	free(point);
}
