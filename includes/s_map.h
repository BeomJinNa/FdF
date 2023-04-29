/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/14 20:32:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

typedef struct s_point
{
	int		value;
	int		color;
	double	x;
	double	y;
	double	z;
	int		proj_i;
	int		proj_j;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**point;
}			t_map;

typedef struct s_status
{
	char	*filename;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	double	scale;
	double	z_ratio;
	double	pov_i;
	double	pov_j;
	double	pov_k;
	double	field_of_view;
	double	rotate_theta;
	double	rotate_phi;
	double	pov_vec[3];
	double	proj_vec_i[3];
	double	proj_vec_j[3];
	int		offset_i;
	int		offset_j;
	int		(*colormap)(int, int);
	t_map	map;
}			t_status;
#endif
