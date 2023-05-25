/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:38:24 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 07:17:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "s_map.h"

int		press_key(int keycode, t_status *stat);
int		close_window(t_status *stat);
void	rotate_view_up(t_status *stat);
void	rotate_view_down(t_status *stat);
void	rotate_view_left(t_status *stat);
void	rotate_view_right(t_status *stat);
void	shift_view_up(t_status *stat);
void	shift_view_down(t_status *stat);
void	shift_view_left(t_status *stat);
void	shift_view_right(t_status *stat);
void	zoom_in(t_status *stat);
void	zoom_out(t_status *stat);
void	increase_z_ratio(t_status *stat);
void	decrease_z_ratio(t_status *stat);
void	reset_settings(t_status *stat);
void	increase_fov(t_status *stat);
void	decrease_fov(t_status *stat);
void	set_colormap(t_status *stat);
#endif
