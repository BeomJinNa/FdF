/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:38:24 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:51:58 by bena             ###   ########.fr       */
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
#endif
