/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dist_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:05:01 by bena              #+#    #+#             */
/*   Updated: 2023/05/15 17:40:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_map.h"

void	create_dist_index(t_status *stat)
{
	const size_t	size = (stat->map.width * stat->map.height) + 1;
	int				i;
	int				j;
	t_point			**ptr;

	stat->map.index = (t_point **)malloc(sizeof(t_point *) * size);
	if (stat->map.index == NULL)
		return ;
	ptr = stat->map.index;
	i = 0;
	while (i < stat->map.height)
	{
		j = 0;
		while (j < stat->map.width)
		{
			*ptr++ = &stat->map.point[i][j];
			j++;
		}
		i++;
	}
	*ptr = NULL;
}
