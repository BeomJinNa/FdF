/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:29:43 by bena              #+#    #+#             */
/*   Updated: 2023/05/24 06:55:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	mix_color(int c1, int c2, int w1, int w2)
{
	const int	total = w1 + w2;
	const int	t = (transparency(c1) * w1 + transparency(c2) * w2) / total;
	const int	r = (red(c1) * w1 + red(c2) * w2) / total;
	const int	g = (green(c1) * w1 + green(c2) * w2) / total;
	const int	b = (blue(c1) * w1 + blue(c2) * w2) / total;

	return (trgb(t, r, g, b));
}
