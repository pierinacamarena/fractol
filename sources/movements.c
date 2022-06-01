/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	color_variation(t_mlx *t)
{
	t->pixel.rr = t->pixel.rr + 1 % 255;
	t->pixel.rb = t->pixel.rb + 10 % 255;
	t->pixel.rg = t->pixel.rg + 100 % 255;
	draw(t);
}


int	close_window(int keycode, t_mlx *t)
{
	if (keycode == ESC)
	{
		mlx_clear_window(t->mlx_ptr, t->win_ptr);
		mlx_destroy_image(t->mlx_ptr, t->img_ptr);
		mlx_destroy_window(t->mlx_ptr, t->win_ptr);
		mlx_destroy_display(t->mlx_ptr);
		free(t->mlx_ptr);
		free(t);
	}
	exit(0);
}

static void	move_fractal(int keycode, t_mlx *t)
{
	t_complex	d;

	d.r = t->xmax - t->xmin;
	d.i = t->ymax - t->ymin;
	if (keycode == DOWN)
	{
		t->ymin -= d.i * 0.05;
		t->ymax -= d.i * 0.05;
	}
	else if (keycode == UP)
	{
		t->ymin += d.i * 0.05;
		t->ymax += d.i * 0.05;
	}
	else if (keycode == RIGHT)
	{
		t->xmin += d.r * 0.05;
		t->xmax += d.r * 0.05;
	}
	else if (keycode == LEFT)
	{
		t->xmin -= d.r * 0.05;
		t->xmax -= d.r * 0.05;
	}
	draw(t);
}

int	key_hook(int keycode, t_mlx *t)
{
	if (keycode == UP || keycode == RIGHT || keycode == LEFT
		|| keycode == DOWN)
		move_fractal(keycode, t);
	else if (keycode == COLOR)
		color_variation(t);
	else if (keycode == ESC)
		close_window(keycode, t);
	return (0);
}
