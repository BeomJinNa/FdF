/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_new_pov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:33:54 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 10:50:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "mlx_run_functions.h"

void	apply_new_pov(t_status *stat)
{
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->rotate_theta);
	get_vertical_unit(stat->proj_vec_y, stat->pov_vec, stat->proj_vec_x);
	refresh_centroid(stat);
	refresh_view_point(stat);
	write_dots_info(stat);
	refresh_dist_index(stat);
	write_proj_info(stat);
	draw_lines(stat);
}
