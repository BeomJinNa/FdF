/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:50:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 12:08:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "e_events.h"
#include "hooks.h"
#include "mlx_run_functions.h"
#include "vector.h"

void		release_points(t_point **point);
static void	init_stat(t_status *stat);
static void	init_stat2(t_status *stat);
static void	alloc_hooks(t_status *stat);

void	run_mlx(t_status *stat)
{
	init_stat(stat);
	init_stat2(stat);
	if (stat->win == NULL)
		close_window(stat);
	alloc_hooks(stat);
	write_dots_info(stat);
	create_dist_index(stat);
	if (stat->map.index == NULL)
		close_window(stat);
	refresh_dist_index(stat);
	write_proj_info(stat);
	draw_lines(stat);
	mlx_loop(stat->mlx);
}

static void	init_stat(t_status *stat)
{
	if (stat->win_width < M_WINDOW_WIDTH_MIN)
		stat->win_width = M_WINDOW_WIDTH_MIN;
	if (stat->win_width > M_WINDOW_WIDTH_MAX)
		stat->win_width = M_WINDOW_WIDTH_MAX;
	if (stat->win_height < M_WINDOW_HEIGHT_MIN)
		stat->win_height = M_WINDOW_HEIGHT_MIN;
	if (stat->win_height > M_WINDOW_HEIGHT_MAX)
		stat->win_height = M_WINDOW_HEIGHT_MAX;
	stat->win_width_2 = stat->win_width / 2;
	stat->win_height_2 = stat->win_height / 2;
	stat->z_ratio = 1.0;
	stat->rotate_theta = M_PI * 3 / 4;
	stat->rotate_phi = M_PI * 3 / 4;
	stat->field_of_view = 0;
	stat->offset_x = 0;
	stat->offset_y = 0;
	stat->win_diagonal = hypot(stat->win_width, stat->win_height);
	stat->map_diagonal = hypot(stat->map.width, stat->map.height);
	stat->ratio_of_win_to_map = stat->win_diagonal / stat->map_diagonal;
	stat->scale = 0.7 * stat->ratio_of_win_to_map;
	stat->field_of_view_max = M_FOV_UNIT_PIXELS * 2 * M_PI / stat->win_diagonal;
}

static void	init_stat2(t_status *stat)
{
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->rotate_theta);
	get_vertical_unit(stat->proj_vec_y, stat->pov_vec, stat->proj_vec_x);
	refresh_centroid(stat);
	refresh_view_point(stat);
	stat->colormap = NULL;
	stat->mlx = NULL;
	stat->win = NULL;
	stat->mlx = mlx_init();
	if (stat->mlx != NULL)
		stat->win = mlx_new_window(stat->mlx, stat->win_width, stat->win_height,
				stat->filename);
}

static void	alloc_hooks(t_status *stat)
{
	mlx_hook(stat->win, ON_DESTROY, 0, close_window, stat);
	mlx_hook(stat->win, ON_KEYDOWN, 0, press_key, stat);
}
