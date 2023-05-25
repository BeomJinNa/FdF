/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:39:16 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 07:20:07 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void	get_min_max_value(t_map *map)
{
	int			i;
	int			j;

	map->min_value = map->point[0][0].value;
	map->max_value = map->point[0][0].value;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->point[i][j].value < map->min_value)
				map->min_value = map->point[i][j].value;
			if (map->point[i][j].value > map->max_value)
				map->max_value = map->point[i][j].value;
		}
	}
}
