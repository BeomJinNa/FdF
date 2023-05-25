/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_centroid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:01:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 06:48:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void	refresh_centroid(t_status *stat)
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
	stat->centroid[0] = (double)temp[0] / total;
	stat->centroid[1] = (double)temp[1] / total;
	stat->centroid[2] = (double)temp[2] * stat->z_ratio / total;
	stat->centroid[0] *= stat->scale;
	stat->centroid[1] *= stat->scale;
	stat->centroid[2] *= stat->scale;
}
