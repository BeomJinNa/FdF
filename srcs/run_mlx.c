/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:50:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:52:42 by bena             ###   ########.fr       */
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
	if (stat->win_width < 100)
		stat->win_width = 100;
	if (stat->win_width > 5000)
		stat->win_width = 5000;
	if (stat->win_height < 100)
		stat->win_height = 100;
	if (stat->win_height > 2500)
		stat->win_height = 2500;
	stat->win_width_2 = stat->win_width / 2;
	stat->win_height_2 = stat->win_height / 2;
	stat->z_ratio = 1.0;
	stat->rotate_theta = M_PI * 3 / 4;
	stat->rotate_phi = M_PI * 3 / 4;
}

static void	init_stat2(t_status *stat)
{
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->rotate_theta);
	get_vertical_unit(stat->proj_vec_y, stat->pov_vec, stat->proj_vec_x);
	get_init_view_point(stat);
	stat->field_of_view = 0;
	stat->offset_x = 0;
	stat->offset_y = 0;
	stat->colormap = NULL;
	stat->mlx = mlx_init();
	stat->win = mlx_new_window(stat->mlx, stat->win_width, stat->win_height,
			stat->filename);
}

static void	alloc_hooks(t_status *stat)
{
	mlx_hook(stat->win, ON_DESTROY, 0, close_window, stat);
	mlx_hook(stat->win, ON_KEYDOWN, 0, press_key, stat);
}
