/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:31:31 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 06:31:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_map.h"

void	release_points(t_point **point)
{
	t_point	**ptr;

	if (point == NULL)
		return ;
	ptr = point;
	while (*ptr != NULL)
		free(*ptr++);
	free(point);
}
