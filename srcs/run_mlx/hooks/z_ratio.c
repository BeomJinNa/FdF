/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_ratio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:05:22 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 04:56:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

void	apply_new_pov(t_status *stat);

void	increase_z_ratio(t_status *stat)
{
	stat->z_ratio *= 1.1;
	apply_new_pov(stat);
}

void	decrease_z_ratio(t_status *stat)
{
	stat->z_ratio /= 1.1;
	apply_new_pov(stat);
}
