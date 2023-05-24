/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 06:58:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	apply_new_pov(t_status *stat);

void	rotate_view_up(t_status *stat)
{
	if (stat->rotate_phi > M_PI / 24)
		stat->rotate_phi -= M_PI / 24;
	else
		stat->rotate_phi = 0;
	apply_new_pov(stat);
}

void	rotate_view_down(t_status *stat)
{
	if (stat->rotate_phi < M_PI * 23 / 24)
		stat->rotate_phi += M_PI / 24;
	else
		stat->rotate_phi = M_PI;
	apply_new_pov(stat);
}

void	rotate_view_left(t_status *stat)
{
	stat->rotate_theta -= M_PI / 24;
	if (stat->rotate_theta < -M_PI)
		stat->rotate_theta += 2 * M_PI;
	else if (stat->rotate_theta > M_PI)
		stat->rotate_theta -= 2 * M_PI;
	apply_new_pov(stat);
}

void	rotate_view_right(t_status *stat)
{
	stat->rotate_theta += M_PI / 24;
	if (stat->rotate_theta < -M_PI)
		stat->rotate_theta += 2 * M_PI;
	else if (stat->rotate_theta > M_PI)
		stat->rotate_theta -= 2 * M_PI;
	apply_new_pov(stat);
}
