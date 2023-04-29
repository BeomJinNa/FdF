/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dots_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:57:04 by bena              #+#    #+#             */
/*   Updated: 2023/05/14 16:38:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"
#include "color.h"

void	write_dots_info(t_status *stat)
{
	int		i;
	int		j;
	t_point	*point;

	i = 0;
	while (i < stat->map.height)
	{
		j = 0;
		while (j < stat->map.width)
		{
			point = &stat->map.point[i][j];
			if (stat->colormap != (void *)0)
				point->color = stat->colormap(point->value, 0);
			else
				point->color = trgb(0, 255, 255, 255);
			point->x = (double)(i * stat->scale);
			point->y = (double)(j * stat->scale);
			point->z = (double)(point->value * stat->scale * stat->z_ratio);
			j++;
		}
		i++;
	}
}
