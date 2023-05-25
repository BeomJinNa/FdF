/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colormap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 08:13:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colormap.h"

void	apply_new_pov(t_status *stat);

void	set_colormap(t_status *stat)
{
	if (stat->colormap == (void *)0)
		stat->colormap = hot_and_cool_colormap;
	else if (stat->colormap == hot_and_cool_colormap)
		stat->colormap = grayscale_colormap;
	else if (stat->colormap == grayscale_colormap)
		stat->colormap = wood_colormap;
	else if (stat->colormap == wood_colormap)
		stat->colormap = rainbow_colormap;
	else if (stat->colormap == rainbow_colormap)
		stat->colormap = sky_colormap;
	else if (stat->colormap == sky_colormap)
		stat->colormap = red_and_blue_colormap;
	else if (stat->colormap == red_and_blue_colormap)
		stat->colormap = white_and_yellow_colormap;
	else if (stat->colormap == white_and_yellow_colormap)
		stat->colormap = (void *)0;
	apply_new_pov(stat);
}
