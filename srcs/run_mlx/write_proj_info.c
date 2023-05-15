/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_proj_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:40:49 by bena              #+#    #+#             */
/*   Updated: 2023/05/15 20:15:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void		get_displacement(double disp[3], t_point *point, t_status *stat);
double		dot_product(double v1[3], double v2[3]);
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
	temp = dot_product(displacement, stat->proj_vec_i);
	if (fabs(temp + (double)stat->offset_i) > (double)stat->win_width)
		point->distance = -1.0;
	point->proj_i = (int)temp + stat->offset_i;
	temp = dot_product(displacement, stat->proj_vec_j);
	if (fabs(temp + (double)stat->offset_j) > (double)stat->win_height)
		point->distance = -1.0;
	point->proj_j = (int)temp + stat->offset_j;
}

/*
static void	proj_parallel(t_status *stat)
{
}
*/
