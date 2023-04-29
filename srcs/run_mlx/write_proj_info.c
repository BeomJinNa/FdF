/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_proj_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:40:49 by bena              #+#    #+#             */
/*   Updated: 2023/05/14 20:33:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void		get_displacement(double disp[3], t_point *point, t_status *stat);
double		dot_product(double v1[3], double v2[3]);
static void	proj_isometric(t_status *stat);
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
	t_point	*point;
	double	displacement[3];

	i = 0;
	while (i < stat->map.height)
	{
		j = 0;
		while (j < stat->map.width)
		{
			point = &stat->map.point[i][j];
			get_displacement(displacement, point, stat);
			point->proj_i = (int)dot_product(displacement, stat->proj_vec_i);
			point->proj_j = (int)dot_product(displacement, stat->proj_vec_j);
			point->proj_i += stat->offset_i;
			point->proj_j += stat->offset_j;
			j++;
		}
		i++;
	}
}

/*
static void	proj_parallel(t_status *stat)
{
}
*/
