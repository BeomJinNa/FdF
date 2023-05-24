/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_proj_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:40:49 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:53:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

static void	proj_isometric(t_status *stat);
static void	set_projected_point(t_point *point, t_status *stat);
//static void	proj_parallel(t_status *stat);

void	write_proj_info(t_status *stat)
{
	if (-0.01 < stat->field_of_view && stat->field_of_view < 0.01)
		proj_isometric(stat);
//	else
//		proj_parallel(stat);
}

static void	proj_isometric(t_status *stat)
{
	int		i;
	int		j;

	i = 0;
	while (i < stat->map.height)
	{
		j = 0;
		while (j < stat->map.width)
		{
			set_projected_point(&stat->map.point[i][j], stat);
			j++;
		}
		i++;
	}
}

static void	set_projected_point(t_point *point, t_status *stat)
{
	double	temp;
	double	displacement[3];

	get_displacement(displacement, point, stat);
	temp = dot_product(displacement, stat->proj_vec_x);
	if (fabs(temp + (double)stat->offset_x) > (double)stat->win_width_2)
		point->distance = -1.0;
	point->proj_x = (int)temp + stat->offset_x;
	temp = dot_product(displacement, stat->proj_vec_y);
	if (fabs(temp + (double)stat->offset_y) > (double)stat->win_height_2)
		point->distance = -1.0;
	point->proj_y = (int)temp + stat->offset_y;
}

/*
static void	proj_parallel(t_status *stat)
{
}
*/
