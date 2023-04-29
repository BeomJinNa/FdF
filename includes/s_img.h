/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:52:01 by bena              #+#    #+#             */
/*   Updated: 2023/05/10 13:57:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_IMG_H
# define S_IMG_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
#endif
