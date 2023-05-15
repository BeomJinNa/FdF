/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:58:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/15 20:19:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAP_H
# define S_MAP_H

typedef struct s_point
{
	int		i;
	int		j;
	int		value;
	int		color;
	int		proj_i;
	int		proj_j;
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
	int		offset_i;
	int		offset_j;
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
	int		(*colormap)(int, int);
	t_map	map;
}			t_status;
#endif
