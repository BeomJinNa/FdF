/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:39:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "s_map.h"
#include "mlx.h"
#include "libft.h"

int			wrong_args(void);
int			are_there_errors_in_args(int ac, char **av);
int			open_error(void);
void		parse_the_map_file(t_map *map, int fd);
int			parsing_error(void);
void		run_mlx(t_status *stat);
static void	set_window_size(int ac, char **av, t_status *stat);

int	main(int ac, char **av)
{
	int			fd;
	t_status	stat;

	if (ac != 2 && ac != 4)
		return (wrong_args());
	if (ac == 4 && are_there_errors_in_args(ac, av))
		return (wrong_args());
	set_window_size(ac, av, &stat);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (open_error());
	parse_the_map_file(&stat.map, fd);
	close(fd);
	if (stat.map.point == NULL)
		return (parsing_error());
	stat.filename = av[1];
	run_mlx(&stat);
	return (0);
}

static void	set_window_size(int ac, char **av, t_status *stat)
{
	if (ac == 2)
	{
		stat->win_width = 1200;
		stat->win_height = 800;
		return ;
	}
	stat->win_width = ft_atoi(av[2]);
	stat->win_height = ft_atoi(av[3]);
}
