/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 04:37:17 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 04:49:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx_run_functions.h"
#include "vector.h"

void	apply_new_pov(t_status *stat);

void	reset_settings(t_status *stat)
{
	stat->z_ratio = 1.0;
	stat->rotate_theta = M_PI * 3 / 4;
	stat->rotate_phi = M_PI * 3 / 4;
	stat->field_of_view = 0;
	stat->offset_x = 0;
	stat->offset_y = 0;
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->rotate_theta);
	get_vertical_unit(stat->proj_vec_y, stat->pov_vec, stat->proj_vec_x);
	get_init_view_point(stat);
	stat->colormap = (void *)0;
	write_dots_info(stat);
	refresh_dist_index(stat);
	write_proj_info(stat);
	draw_lines(stat);
}
