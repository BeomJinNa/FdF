/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_run_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:36:05 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:59:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RUN_FUNCTIONS_H
# define MLX_RUN_FUNCTIONS_H

# include "s_map.h"

void	get_init_view_point(t_status *stat);
void	write_dots_info(t_status *stat);
void	write_proj_info(t_status *stat);
void	create_dist_index(t_status *stat);
void	refresh_dist_index(t_status *stat);
void	draw_lines(t_status *stat);
#endif
