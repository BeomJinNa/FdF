/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_view_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:01:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 06:55:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	refresh_view_point(t_status *stat)
{
	double	distance = stat->scale * 1000;

	stat->pov_i = stat->centroid_i - stat->pov_vec[0] * distance;
	stat->pov_j = stat->centroid_j - stat->pov_vec[1] * distance;
	stat->pov_k = stat->centroid_k - stat->pov_vec[2] * distance;
}
