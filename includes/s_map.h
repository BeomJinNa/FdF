/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 02:46:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

typedef struct s_line
{
	int		x;
	int		y;
	int		color;
	int		axis;
	int		unit_x;
	int		unit_y;
	int		p1_x;
	int		p1_y;
	int		p2_x;
	int		p2_y;
	int		p1_color;
	int		p2_color;
	int		axis_len;
	int		side_len;
}			t_line;

typedef struct s_point
{
	int		i;
	int		j;
	int		value;
	int		color;
	int		proj_x;
	int		proj_y;
	double	x;
	double	y;
	double	z;
	double	distance;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**index;
	t_point	**point;
}			t_map;

typedef struct s_status
{
	char	*filename;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		win_width_2;
	int		win_height_2;
	int		offset_x;
	int		offset_y;
	double	scale;
	double	z_ratio;
	double	pov_i;
	double	pov_j;
	double	pov_k;
	double	centroid_i;
	double	centroid_j;
	double	centroid_k;
	double	field_of_view;
	double	rotate_theta;
	double	rotate_phi;
	double	pov_vec[3];
	double	proj_vec_x[3];
	double	proj_vec_y[3];
	int		(*colormap)(int, int);
	t_map	map;
}			t_status;
#endif
