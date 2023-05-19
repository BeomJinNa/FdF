/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init_view_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:01:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/24 08:20:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

static void	calc_variables(t_status *stat);

void	get_init_view_point(t_status *stat)
{
	int			i;
	int			j;
	long long	temp[3];
	const int	total = stat->map.width * stat->map.height;

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	i = -1;
	while (++i < stat->map.height)
	{
		j = -1;
		while (++j < stat->map.width)
		{
			temp[0] += i;
			temp[1] += j;
			temp[2] += stat->map.point[i][j].value;
		}
	}
	stat->centroid_i = (double)temp[0] / total;
	stat->centroid_j = (double)temp[1] / total;
	stat->centroid_k = (double)temp[2] * stat->z_ratio / total;
	calc_variables(stat);
}

static void	calc_variables(t_status *stat)
{
	stat->scale = 0.7 * sqrt(stat->win_width * stat->win_width
			+ stat->win_height * stat->win_height)
		/ sqrt(stat->map.width * stat->map.width
			+ stat->map.height * stat->map.height);
	stat->centroid_i *= stat->scale;
	stat->centroid_j *= stat->scale;
	stat->centroid_k *= stat->scale;
	stat->pov_i = stat->centroid_i - stat->pov_vec[0] * stat->scale * 1000;
	stat->pov_j = stat->centroid_j - stat->pov_vec[1] * stat->scale * 1000;
	stat->pov_k = stat->centroid_k - stat->pov_vec[2] * stat->scale * 1000;
}
