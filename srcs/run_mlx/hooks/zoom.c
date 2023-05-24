/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 04:21:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "s_map.h"

void	apply_new_pov(t_status *stat);

void	zoom_in(t_status *stat)
{
	stat->scale *= 1.1;
	apply_new_pov(stat);
}

void	zoom_out(t_status *stat)
{
	stat->scale /= 1.1;
	apply_new_pov(stat);
}
