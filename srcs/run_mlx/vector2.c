/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:35 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 04:19:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	get_angular_coordinate(double p[3], double u[3], double h[3])
{
	const double	projection_to_u = dot_product(u, p);
	const double	projection_to_h = dot_product(h, p);

	return (
		acos(
			projection_to_u / hypot(projection_to_u, projection_to_h)
		)
	);
}
