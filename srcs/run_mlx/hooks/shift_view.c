/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 05:32:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void	apply_new_pov(t_status *stat);

void	shift_view_up(t_status *stat)
{
	stat->offset_y -= 64;
	apply_new_pov(stat);
}

void	shift_view_down(t_status *stat)
{
	stat->offset_y += 64;
	apply_new_pov(stat);
}

void	shift_view_left(t_status *stat)
{
	stat->offset_x -= 64;
	apply_new_pov(stat);
}

void	shift_view_right(t_status *stat)
{
	stat->offset_x += 64;
	apply_new_pov(stat);
}
