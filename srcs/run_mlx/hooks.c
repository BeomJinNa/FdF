/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:53:15 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "e_keycodes.h"
#include "hooks.h"

void	release_points(t_point **point);

int	close_window(t_status *stat)
{
	mlx_destroy_window(stat->mlx, stat->win);
	if (stat->map.index != NULL)
		free(stat->map.index);
	release_points(stat->map.point);
	exit(0);
}

int	press_key(int keycode, t_status *stat)
{
	if (keycode == KEY_ESCAPE)
		close_window(stat);
	else if (keycode == KEY_W)
		rotate_view_up(stat);
	else if (keycode == KEY_A)
		rotate_view_left(stat);
	else if (keycode == KEY_S)
		rotate_view_down(stat);
	else if (keycode == KEY_D)
		rotate_view_right(stat);
	else if (keycode == KEY_H)
		shift_view_left(stat);
	else if (keycode == KEY_J)
		shift_view_down(stat);
	else if (keycode == KEY_K)
		shift_view_up(stat);
	else if (keycode == KEY_L)
		shift_view_right(stat);
	return (0);
}
