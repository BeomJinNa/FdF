/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_view_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:01:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 07:21:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	refresh_view_point(t_status *stat)
{
	double	distance;

	if (fabs(stat->field_of_view) < M_ISOMETRIC_CUTOFF)
		distance = (double)M_FOV_UNIT_PIXELS / M_ISOMETRIC_CUTOFF;
	else
		distance = (double)M_FOV_UNIT_PIXELS / stat->field_of_view;
	stat->pov[0] = stat->centroid[0] - stat->pov_vec[0] * distance;
	stat->pov[1] = stat->centroid[1] - stat->pov_vec[1] * distance;
	stat->pov[2] = stat->centroid[2] - stat->pov_vec[2] * distance;
}
