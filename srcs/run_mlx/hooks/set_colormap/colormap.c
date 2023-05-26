/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:27:20 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 09:58:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"
#include "color.h"

int	red_and_blue_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	return (
		mix_color(trgb(0, 0xFF, 0x30, 0x30), trgb(0, 0x30, 0x30, 0xFF),
			value - min, max - value)
	);
}

int	white_and_yellow_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	return (
		mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0x80, 0x80, 0x00),
			value - min, max - value)
	);
}

int	sky_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	return (
		mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0x40, 0x80, 0xAA),
			value - min, max - value)
	);
}
