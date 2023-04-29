/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/05/14 20:07:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	sphere_to_vec(double vector[3], double theta, double phi)
{
	vector[0] = cos(theta);
	vector[1] = sin(theta);
	vector[2] = cos(phi);
}

void	get_horizontal_unit(double h_unit[3], double vector[3])
{
	double	size;

	h_unit[0] = - (vector[1] * vector[2]);
	h_unit[1] = vector[0] * vector[2];
	h_unit[2] = 0;
	size = sqrt(h_unit[0] * h_unit[0] + h_unit[1] * h_unit[1]);
	if (vector[2] > 0)
		size = -size;
	h_unit[0] /= size;
	h_unit[1] /= size;
}

void	get_vertical_unit(double v_unit[3], double h_unit[3], double vec[3])
{
	double	size;

	v_unit[0] = vec[1] * h_unit[2] - (h_unit[1] * vec[2]);
	v_unit[1] = h_unit[0] * vec[2] - (vec[0] * h_unit[2]);
	v_unit[2] = vec[0] * h_unit[1] - (h_unit[0] * vec[1]);
	size = sqrt(v_unit[0] * v_unit[0] + v_unit[1] * v_unit[1]
			+ v_unit[2] * v_unit[2]);
	v_unit[0] /= size;
	v_unit[1] /= size;
	v_unit[2] /= size;
}

void	get_displacement(double disp[3], t_point *point, t_status *stat)
{
	disp[0] = point->x - stat->pov_i;
	disp[1] = point->y - stat->pov_j;
	disp[2] = point->z - stat->pov_k;
}

double	dot_product(double v1[3], double v2[3])
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}
