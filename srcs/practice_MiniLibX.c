/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:23:16 by bena              #+#    #+#             */
/*   Updated: 2023/04/28 07:49:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

enum events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


typedef struct s_circle
{
	int	x;
	int	y;
	int	r;
}		t_circle;
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_circle	*circle;
}			t_vars;

typedef struct s_img{
  void	*img;
  char	*addr;
  int	bits_per_pixel;
  int	line_length;
  int	endian;
}		t_img;


typedef struct s_color
{
	int		color;
	void	*mlx;
	void	*win;
}t_color;

void	img_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_vars *vars);
void	render_circle(t_vars *vars, t_circle *circle);
int	press_key(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->circle->y -= 100;
	if (keycode == 0)
		vars->circle->x -= 100;
	if (keycode == 1)
		vars->circle->y += 100;
	if (keycode == 2)
		vars->circle->x += 100;
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		render_circle(vars, vars->circle);
		return (0);
	}
	if (keycode == 53)
		close_window(vars);
	printf("pressed key code : %d\n", keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	printf("window closed\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)vars;
	(void)x;
	(void)y;
//	printf("mouse position x : %d, y : %d\n", x, y);
	return (1);
}

int	trgb(int transparency, int red, int green, int blue)
{
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

int transparency(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	blue(int trgb)
{
	return (trgb & 0xFF);
}

int	get_next_color(int trgb)
{
	if (red(trgb) > 0 && blue(trgb) == 0)
		return (trgb - (1 << 16) + (1 << 8));
	if (green(trgb) > 0 && red(trgb) == 0)
		return (trgb - (1 << 8) + 1);
	if (blue(trgb) > 0 && green(trgb) == 0)
		return (trgb - 1 + (1 << 16));
	return (0);
}

int render_rainbow(t_color *color)
{
	t_img	img;

	img.img = mlx_new_image(color->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x;
	int y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			img_mlx_pixel_put(&img, x, y, color->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(color->mlx, color->win, img.img, 1500,800);
	color->color = get_next_color(color->color);
	return (0);
}

void	render_circle(t_vars *vars, t_circle *circle)
{
	t_img	img;

	img.img = mlx_new_image(vars->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int top = circle->y - circle->r;
	int bottom = circle->y + circle->r;
	int left = circle->x - circle->r;
	int right = circle->x + circle->r;
	if (top < 0)
		top = 0;
	if (top > 1079)
		top = 1079;
	if (bottom < 0)
		bottom = 0;
	if (bottom > 1079)
		bottom = 1079;
	if (left < 0)
		left = 0;
	if (left > 1919)
		left = 1919;
	if (right < 0)
		right = 0;
	if (right > 1919)
		right = 1919;
	int x;
	int y = top;
	double distance;
	while (y <= bottom)
	{
		x = left;
		while (x <= right)
		{
			distance = sqrt((circle->y - y) * (circle->y - y) + (circle->x - x) * (circle->x - x));
			if (fabs(distance - circle->r) < 1)
			{
				img_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	main(void)
{
	t_vars		vars;
	t_color		color;
	t_circle	circle;

	circle.x = 960;
	circle.y = 540;
	circle.r = 400;
	vars.circle = &circle;
	color.color = trgb(0, 255, 0, 0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_string_put(vars.mlx, vars.win, 960,540,0x00FFFFFF, "WELCOME");
	color.mlx = vars.mlx;
	color.win = vars.win;
	mlx_hook(vars.win, ON_KEYDOWN, 0, press_key, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
//	mlx_loop_hook(vars.mlx, render_rainbow, &color);
	mlx_loop(vars.mlx);
	return (0);
}
