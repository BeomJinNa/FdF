/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 12:06:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "e_keycodes.h"
#include "hooks.h"

void		release_points(t_point **point);
static int	press_key2(int keycode, t_status *stat);

int	close_window(t_status *stat)
{
	if (stat->win != NULL)
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
		rotate_view_down(stat);
	else if (keycode == KEY_A)
		rotate_view_left(stat);
	else if (keycode == KEY_S)
		rotate_view_up(stat);
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
	return (press_key2(keycode, stat));
}

static int	press_key2(int keycode, t_status *stat)
{
	if (keycode == KEY_I)
		zoom_in(stat);
	else if (keycode == KEY_O)
		zoom_out(stat);
	else if (keycode == KEY_Q)
		decrease_z_ratio(stat);
	else if (keycode == KEY_E)
		increase_z_ratio(stat);
	else if (keycode == KEY_R)
		reset_settings(stat);
	else if (keycode == KEY_Z)
		decrease_fov(stat);
	else if (keycode == KEY_X)
		increase_fov(stat);
	else if (keycode == KEY_C)
		set_colormap(stat);
	return (0);
}
