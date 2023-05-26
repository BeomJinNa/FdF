/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:05:04 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 12:15:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "image.h"
#include "color.h"
#include "hooks.h"

int			ft_abs(int num);
static void	draw_lines_at_the_point(t_img *img, t_point *point, t_status *stat);
static void	connect_two_points(t_point *p1, t_point *p2,
				t_img *img, t_status *stat);
static void	get_axis_data(t_line *line);
static void	get_next_pixel(t_line *line);

void	draw_lines(t_status *stat)
{
	const t_map	*map = &stat->map;
	const int	size = map->width * map->height;
	int			index;
	t_point		*point;
	t_img		image;

	image.img = mlx_new_image(stat->mlx, stat->win_width, stat->win_height);
	if (image.img == (void *)0)
		close_window(stat);
	get_image_address(&image);
	index = 0;
	while (index < size)
	{
		point = map->index[index];
		draw_lines_at_the_point(&image, point, stat);
		index++;
	}
	mlx_put_image_to_window(stat->mlx, stat->win, image.img, 0, 0);
	mlx_destroy_image(stat->mlx, image.img);
}

static void	draw_lines_at_the_point(t_img *img, t_point *point, t_status *stat)
{
	const t_map	*map = &stat->map;
	const int	i = point->i;
	const int	j = point->j;

	if (point->distance < 0)
		return ;
	if (i + 1 < map->height
		&& (map->point[i + 1][j]).distance >= 0)
		connect_two_points(point, &map->point[i + 1][j], img, stat);
	if (j + 1 < map->width
		&& (map->point[i][j + 1]).distance >= 0)
		connect_two_points(point, &map->point[i][j + 1], img, stat);
}

static void	connect_two_points(t_point *p1, t_point *p2,
				t_img *img, t_status *stat)
{
	t_line		line;
	const int	shift_x = stat->win_width_2;
	const int	shift_y = stat->win_height_2;

	line.p1_x = p1->proj_x + shift_x;
	line.p1_y = p1->proj_y + shift_y;
	line.p2_x = p2->proj_x + shift_x;
	line.p2_y = p2->proj_y + shift_y;
	line.p1_color = p1->color;
	line.p2_color = p2->color;
	get_axis_data(&line);
	if (line.x >= 0 && line.y >= 0
		&& line.x < stat->win_width && line.y < stat->win_height)
		img_mlx_pixel_put(img, line.x, line.y, line.color);
	while (line.x != line.p2_x || line.y != line.p2_y)
	{
		get_next_pixel(&line);
		if (line.x >= 0 && line.y >= 0
			&& line.x < stat->win_width && line.y < stat->win_height)
			img_mlx_pixel_put(img, line.x, line.y, line.color);
	}
}

static void	get_axis_data(t_line *line)
{
	line->x = line->p1_x;
	line->y = line->p1_y;
	line->color = line->p1_color;
	if (ft_abs(line->p2_y - line->p1_y) <= ft_abs(line->p2_x - line->p1_x))
		line->axis = 1;
	else
		line->axis = -1;
	if (line->p2_x > line->p1_x)
		line->unit_x = 1;
	else
		line->unit_x = -1;
	if (line->p2_y > line->p1_y)
		line->unit_y = 1;
	else
		line->unit_y = -1;
	if (line->axis == 1)
	{
		line->axis_len = ft_abs(line->p2_x - line->p1_x);
		line->side_len = ft_abs(line->p2_y - line->p1_y);
	}
	else
	{
		line->side_len = ft_abs(line->p2_x - line->p1_x);
		line->axis_len = ft_abs(line->p2_y - line->p1_y);
	}
}

static void	get_next_pixel(t_line *line)
{
	int	w1;
	int	w2;

	if (line->axis == 1)
		line->x += line->unit_x;
	else
		line->y += line->unit_y;
	if (line->axis == 1)
		if (2 * line->side_len * ft_abs(line->p1_x - line->x) - 2
			* line->axis_len * ft_abs(line->p1_y - line->y) > line->axis_len)
			line->y += line->unit_y;
	if (line->axis == -1)
		if (2 * line->side_len * ft_abs(line->p1_y - line->y) - 2
			* line->axis_len * ft_abs(line->p1_x - line->x) > line->axis_len)
			line->x += line->unit_x;
	if (line->p1_color != line->p2_color)
	{
		if (line->axis == 1)
			w1 = ft_abs(line->x - line->p2_x);
		else
			w1 = ft_abs(line->y - line->p2_y);
		w2 = line->axis_len - w1;
		line->color = mix_color(line->p1_color, line->p2_color, w1, w2);
	}
}
