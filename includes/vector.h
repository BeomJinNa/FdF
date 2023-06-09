/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:47:36 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 04:14:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "s_map.h"

void	sphere_to_vec(double vector[3], double theta, double phi);
void	get_horizontal_unit(double h_unit[3], double theta);
void	get_vertical_unit(double v_unit[3], double vec[3], double h_unit[3]);
void	get_displacement(double disp[3], t_point *point, t_status *stat);
double	dot_product(double v1[3], double v2[3]);
double	get_angular_coordinate(double p[3], double u[3], double h[3]);
#endif
