/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:02 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/14 13:28:39 by alangloi         ###   ########.fr       */
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
	if (keycode == ESCKEY)
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
	if (keycode == ARROW_DOWN)
	{
		t->ymin -= d.i * 0.05;
		t->ymax -= d.i * 0.05;
	}
	else if (keycode == ARROW_UP)
	{
		t->ymin += d.i * 0.05;
		t->ymax += d.i * 0.05;
	}
	else if (keycode == ARROW_RIGHT)
	{
		t->xmin += d.r * 0.05;
		t->xmax += d.r * 0.05;
	}
	else if (keycode == ARROW_LEFT)
	{
		t->xmin -= d.r * 0.05;
		t->xmax -= d.r * 0.05;
	}
	draw(t);
}

int	key_hook(int keycode, t_mlx *t)
{
	if (keycode == ARROW_UP || keycode == ARROW_RIGHT || keycode == ARROW_LEFT
		|| keycode == ARROW_DOWN)
		move_fractal(keycode, t);
	else if (keycode == COLORKEY)
		color_variation(t);
	else if (keycode == ESCKEY)
		close_window(keycode, t);
	return (0);
}
