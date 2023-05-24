/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_new_pov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:33:54 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:59:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "mlx_run_functions.h"

void	apply_new_pov(t_status *stat)
{
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->rotate_theta);
	get_vertical_unit(stat->proj_vec_y, stat->pov_vec, stat->proj_vec_x);
	//*1000은 parallel에서는 수정되어야 함 적당한 값으로
	stat->pov_i = stat->centroid_i - stat->pov_vec[0] * stat->scale * 1000;
	stat->pov_j = stat->centroid_j - stat->pov_vec[1] * stat->scale * 1000;
	stat->pov_k = stat->centroid_k - stat->pov_vec[2] * stat->scale * 1000;
	write_dots_info(stat);
	refresh_dist_index(stat);
	write_proj_info(stat);
	draw_lines(stat);
}
