/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/14 17:08:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "s_map.h"

int		close_window(t_status *stat);
int		press_key(int keycode, t_status *stat);
void	release_points(t_point **point);

int	close_window(t_status *stat)
{
	ft_printf("window closed\n");
	mlx_destroy_window(stat->mlx, stat->win);
	release_points(stat->map.point);
	exit(0);
}

int	press_key(int keycode, t_status *stat)
{
	if (keycode == 53)
		close_window(stat);
	return (0);
}
