/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/05/24 07:42:44 by bena             ###   ########.fr       */
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

//TEST
void	leaks(void)
{
	system ("leaks fdf");
}
//TEST
int	main(int ac, char **av)
{
	int			fd;
	t_status	stat;

//	atexit(leaks);//TEST
	if (ac != 2)
		return (wrong_args());
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (open_error());
	printf("start parsing\n"); //TEST
	parse_the_map_file(&stat.map, fd);
	close(fd);
	if (stat.map.point == NULL)
		return (parsing_error());
	stat.filename = av[1];
	stat.win_width = 1920;
	stat.win_height = 1080;
	//TEST START
	printf("parsed map\n");
	for (int i = 0 ; i < stat.map.height ; i++)
	{
		for (int j = 0 ; j < stat.map.width ; j++)
			printf("%3d ", stat.map.point[i][j].value);
		printf("\n");
	}
	//TEST END
	printf("mlx running\n"); //TEST
	run_mlx(&stat);
	printf("mlx exit\n"); //TEST
	release_points(stat.map.point);
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
