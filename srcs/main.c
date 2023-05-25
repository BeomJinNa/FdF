/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:53:11 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 06:37:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "s_map.h"
#include "mlx.h"

int		wrong_args(void);
int		open_error(void);
void	parse_the_map_file(t_map *map, int fd);
int		parsing_error(void);
void	run_mlx(t_status *stat);

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
