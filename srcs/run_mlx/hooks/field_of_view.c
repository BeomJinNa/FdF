/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 05:31:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	apply_new_pov(t_status *stat);

void	increase_fov(t_status *stat)
{
	if (stat->field_of_view < M_ISOMETRIC_CUTOFF)
		stat->field_of_view = M_ISOMETRIC_CUTOFF;
	else if (stat->field_of_view < M_ISOMETRIC_CUTOFF * 5.0)
		stat->field_of_view *= 1.4;
	else if (stat->field_of_view * 1.1 < stat->field_of_view_max)
		stat->field_of_view *= 1.1;
	apply_new_pov(stat);
}

void	decrease_fov(t_status *stat)
{
	if (stat->field_of_view < M_ISOMETRIC_CUTOFF)
		stat->field_of_view = 0;
	else if (stat->field_of_view / 1.1 < M_ISOMETRIC_CUTOFF * 5.0)
		stat->field_of_view /= 1.4;
	else
		stat->field_of_view /= 1.1;
	apply_new_pov(stat);
}
