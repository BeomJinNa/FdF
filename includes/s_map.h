/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 09:39:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

# define M_WINDOW_WIDTH_MIN 300
# define M_WINDOW_WIDTH_MAX 2550
# define M_WINDOW_HEIGHT_MIN 300
# define M_WINDOW_HEIGHT_MAX 1380
# define M_ISOMETRIC_CUTOFF 0.01
# define M_FOV_UNIT_PIXELS 1000

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
	int		min_value;
	int		max_value;
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
	double	field_of_view;
	double	field_of_view_max;
	double	rotate_theta;
	double	rotate_phi;
	double	centroid[3];
	double	pov[3];
	double	pov_vec[3];
	double	proj_vec_x[3];
	double	proj_vec_y[3];
	double	win_diagonal;
	double	map_diagonal;
	double	ratio_of_win_to_map;
	int		(*colormap)(int, struct s_status *stat);
	t_map	map;
}			t_status;
#endif
