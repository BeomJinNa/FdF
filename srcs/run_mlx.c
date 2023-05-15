/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:50:16 by bena              #+#    #+#             */
/*   Updated: 2023/05/15 20:19:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "e_events.h"
#include "s_map.h"

int			close_window(t_status *stat);
int			press_key(int keycode, t_status *stat);
void		release_points(t_point **point);
void		write_dots_info(t_status *stat);
void		write_proj_info(t_status *stat);
void		create_dist_index(t_status *stat);
void		refresh_dist_index(t_status *stat);
void		sphere_to_vec(double *vector, double theta, double phi);
void		get_horizontal_unit(double h_unit[3], double vector[3]);
void		get_vertical_unit(double v_unit[3], double h_unit[3],
				double vec[3]);
static void	init_stat(t_status *stat);
static void	alloc_hooks(t_status *stat);

#include <stdio.h> //TEST
void	run_mlx(t_status *stat)
{
	init_stat(stat);
	alloc_hooks(stat);
	write_dots_info(stat);
	create_dist_index(stat);
	refresh_dist_index(stat);
	if (stat->map.index == NULL)
		close_window(stat);
	write_proj_info(stat);
	//TEST
	for (int i = 0 ; i < stat->map.height ; i++)
	{
		for (int j = 0 ; j < stat->map.width ; j++)
			printf("%6.1f ", stat->map.point[i][j].distance);
		printf("\n");
	}
//	t_point **ptr = stat->map.index;
//	for (int i = 0 ; i < stat->map.height * stat->map.width ; i++)
//		printf("i: %d, j: %d, (%3.1f, %3.1f, %3.1f), dist: %4.1f\n", (*(ptr + i))->i, (*(ptr + i))->j, (*(ptr + i))->x, (*(ptr + i))->y, (*(ptr + i))->z, (*(ptr + i))->distance);
	//TESTEND
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
	stat->scale = 30.0;
	stat->z_ratio = 1.0;
	stat->pov_i = 0;
	stat->pov_j = 0;
	stat->pov_k = 10.0;
	stat->rotate_theta = M_PI_4;
	stat->rotate_phi = M_PI * 3 / 4;
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_i, stat->pov_vec);
	get_vertical_unit(stat->proj_vec_j, stat->proj_vec_i, stat->pov_vec);
	stat->field_of_view = 0;
	stat->offset_i = 0;
	stat->offset_j = 0;
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
