/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_new_pov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:33:54 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 01:39:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void		sphere_to_vec(double *vector, double theta, double phi);
void		get_horizontal_unit(double h_unit[3], double vector[3]);
void		get_vertical_unit(double v_unit[3], double vec[3],
				double h_unit[3]);
void		write_dots_info(t_status *stat);
void		refresh_dist_index(t_status *stat);
void		write_proj_info(t_status *stat);
void		draw_lines(t_status *stat);

void	apply_new_pov(t_status *stat)
{
	sphere_to_vec(stat->pov_vec, stat->rotate_theta, stat->rotate_phi);
	get_horizontal_unit(stat->proj_vec_x, stat->pov_vec);
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
