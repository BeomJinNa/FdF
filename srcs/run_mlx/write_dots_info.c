/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dots_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:57:04 by bena              #+#    #+#             */
/*   Updated: 2023/05/30 18:59:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "vector.h"

static double	get_distance(t_point *point, t_status *stat);

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
				point->color = stat->colormap(point->value, stat);
			else
				point->color = trgb(0, 255, 255, 255);
			point->i = i;
			point->j = j;
			point->x = (i * stat->scale);
			point->y = (j * stat->scale);
			point->z = (point->value * stat->scale * stat->z_ratio);
			point->distance = get_distance(point, stat);
			j++;
		}
		i++;
	}
}

static double	get_distance(t_point *point, t_status *stat)
{
	double	displacement[3];
	double	distance;

	get_displacement(displacement, point, stat);
	distance = dot_product(displacement, displacement);
	if (stat->field_of_view < M_ISOMETRIC_CUTOFF
		&& dot_product(displacement, stat->pov_vec) < 0)
		distance = -distance;
	return (distance);
}
