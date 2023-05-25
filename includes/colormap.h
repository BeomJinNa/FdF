/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:13:32 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 08:13:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORMAP_H
# define COLORMAP_H

# include "s_map.h"

int	hot_and_cool_colormap(int value, t_status *stat);
int	grayscale_colormap(int value, t_status *stat);
int	wood_colormap(int value, t_status *stat);
int	rainbow_colormap(int value, t_status *stat);
int	sky_colormap(int value, t_status *stat);
int	red_and_blue_colormap(int value, t_status *stat);
int	white_and_yellow_colormap(int value, t_status *stat);
#endif
