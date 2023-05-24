/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:42:53 by bena              #+#    #+#             */
/*   Updated: 2023/05/25 03:44:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "s_img.h"

void	img_mlx_pixel_put(t_img *data, int x, int y, int color);
void	get_image_address(t_img *img);
#endif
