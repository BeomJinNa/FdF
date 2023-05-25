/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:27:20 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 08:18:31 by bena             ###   ########.fr       */
/* ************************************************************************** */

#include "s_map.h"
#include "color.h"

int	rainbow_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	if (value < min + (int)((max - min) / 3))
		return (
			mix_color(trgb(0, 0, 0xFF, 0), trgb(0, 0xFF, 0, 0),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0, 0, 0xFF), trgb(0, 0, 0xFF, 0),
				value - (min + (int)((max - min) / 3)),
				min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0, 0), trgb(0, 0, 0, 0xFF),
				value - (min + (int)((max - min) * 2 / 3)),
				max - value)
		);
}

int	hot_and_cool_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	if (value < min + (int)((max - min) / 3))
		return (
			mix_color(trgb(0, 0, 0xFF, 0), trgb(0, 0, 0, 0xFF),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xFF, 0, 0), trgb(0, 0, 0xFF, 0),
				value - (min + (int)((max - min) / 3)),
				min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0xFF, 0, 0),
				value - (min + (int)((max - min) * 2 / 3)),
				max - value)
		);
}

int	wood_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	if (value < min + (int)((max - min) / 3))
		return (
			mix_color(trgb(0, 0xCC, 0x80, 0), trgb(0, 0x80, 0x55, 0),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xFF, 0xAA, 0), trgb(0, 0xCC, 0x80, 0),
				value - (min + (int)((max - min) / 3)),
				min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0xFF, 0xAA, 0),
				value - (min + (int)((max - min) * 2 / 3)),
				max - value)
		);
}

int	grayscale_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	if (value < min + (int)((max - min) / 3))
		return (
			mix_color(trgb(0, 0x80, 0x80, 0x80), trgb(0, 0x50, 0x50, 0x50),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xAA, 0xAA, 0xAA), trgb(0, 0x80, 0x80, 0x80),
				value - (min + (int)((max - min) / 3)),
				min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0xAA, 0xAA, 0xAA),
				value - (min + (int)((max - min) * 2 / 3)),
				max - value)
		);
}
