/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:27:20 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:41:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"
#include "color.h"

int	rainbow_colormap(int value, t_status *stat)
{
	const int	min = stat->map.min_value;
	const int	max = stat->map.max_value;

	if (value < min + (int)((max - min) / 3))
		return (
			mix_color(trgb(0, 0x40, 0xFF, 0x40), trgb(0, 0xFF, 0x40, 0x40),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0x40, 0x40, 0xFF), trgb(0, 0x40, 0xFF, 0x40),
				value - (min + (int)((max - min) / 3)),
			min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0x40, 0x40), trgb(0, 0x40, 0x40, 0xFF),
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
			mix_color(trgb(0, 0xCC, 0xCC, 0xFF), trgb(0, 0, 0, 0xFF),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xFF, 0xCC, 0xCC), trgb(0, 0xCC, 0xCC, 0xFF),
				value - (min + (int)((max - min) / 3)),
			min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0, 0), trgb(0, 0xFF, 0xCC, 0xCC),
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
			mix_color(trgb(0, 0xAA, 0x60, 0), trgb(0, 0x60, 0x20, 0),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xCC, 0x99, 0), trgb(0, 0xAA, 0x60, 0),
				value - (min + (int)((max - min) / 3)),
			min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0xCC, 0x99, 0),
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
			mix_color(trgb(0, 0x60, 0x60, 0x60), trgb(0, 0x20, 0x20, 0x20),
				value - min,
				min + (int)((max - min) / 3) - value)
		);
	else if (value < min + (int)((max - min) * 2 / 3))
		return (
			mix_color(trgb(0, 0xCC, 0xCC, 0xCC), trgb(0, 0x60, 0x60, 0x60),
				value - (min + (int)((max - min) / 3)),
			min + (int)((max - min) * 2 / 3) - value)
		);
	else
		return (
			mix_color(trgb(0, 0xFF, 0xFF, 0xFF), trgb(0, 0xCC, 0xCC, 0xCC),
				value - (min + (int)((max - min) * 2 / 3)),
			max - value)
		);
}
