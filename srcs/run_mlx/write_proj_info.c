/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_proj_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:40:49 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:37:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

int			ft_abs(int num);
static void	proj_isometric(t_status *stat);
static void	set_point_projection_isometric(t_point *point, t_status *stat);
static void	proj_perspective(t_status *stat);
static void	set_point_projection_perspective(t_point *point, t_status *stat);

void	write_proj_info(t_status *stat)
{
	if (fabs(stat->field_of_view) < M_ISOMETRIC_CUTOFF)
		proj_isometric(stat);
	else
		proj_perspective(stat);
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
			set_point_projection_isometric(&stat->map.point[i][j], stat);
			j++;
		}
		i++;
	}
}

static void	set_point_projection_isometric(t_point *point, t_status *stat)
{
	double	temp;
	double	displacement[3];

	get_displacement(displacement, point, stat);
	temp = dot_product(displacement, stat->proj_vec_x);
	point->proj_x = (int)temp + stat->offset_x;
	if (ft_abs(point->proj_x) > stat->win_width_2)
		point->distance = -1.0;
	temp = dot_product(displacement, stat->proj_vec_y);
	point->proj_y = (int)temp + stat->offset_y;
	if (ft_abs(point->proj_y) > stat->win_height_2)
		point->distance = -1.0;
}

static void	proj_perspective(t_status *stat)
{
	int		i;
	int		j;

	i = 0;
	while (i < stat->map.height)
	{
		j = 0;
		while (j < stat->map.width)
		{
			set_point_projection_perspective(&stat->map.point[i][j], stat);
			j++;
		}
		i++;
	}
}

static void	set_point_projection_perspective(t_point *point, t_status *stat)
{
	double	displacement[3];
	double	d_theta_x;
	double	d_theta_y;

	get_displacement(displacement, point, stat);
	d_theta_x = get_angular_coordinate(displacement,
			stat->pov_vec, stat->proj_vec_x);
	if (dot_product(displacement, stat->proj_vec_x) < 0)
		d_theta_x = -d_theta_x;
	point->proj_x = (int)(d_theta_x * M_FOV_UNIT_PIXELS / stat->field_of_view)
		+ stat->offset_x;
	if (ft_abs(point->proj_x) > stat->win_width_2)
		point->distance = -1.0;
	d_theta_y = get_angular_coordinate(displacement,
			stat->pov_vec, stat->proj_vec_y);
	if (dot_product(displacement, stat->proj_vec_y) < 0)
		d_theta_y = -d_theta_y;
	point->proj_y = (int)(d_theta_y * M_FOV_UNIT_PIXELS / stat->field_of_view)
		+ stat->offset_y;
	if (ft_abs(point->proj_y) > stat->win_height_2)
		point->distance = -1.0;
}
