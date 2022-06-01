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

/*
 * this function allows the change of color when the c key is pressed
*/

static void	color_change(t_mlx  *f)
{
	f->pixel.rr = f->pixel.rr + 1 % 255;
	f->pixel.rb = f->pixel.rb + 10 % 255;
	f->pixel.rg = f->pixel.rg + 100 % 255;
	display_fractal(f);
}

/*
 * this function closes window when esc is pressed,
 * if program is running on macos choose 53 for keycode
 * if program is running on vm linux choose 65515 for keycode
*/

int	close_window(int keycode, t_mlx  *f)
{
	if (keycode == ESCKEY)
		free(f);
	exit(0);
}

/*
 * this function allows the moving of the fractal,
 * if on macos choose
 * 126 for down
 * 125 for up
 * 124 for right
 * 123 for left
 * if on vm linux choose
 * 65364 for up
 * 65362 for down
 * 65361 for left
 * 65363 for right
*/

static void	move_fractal(int keycode, t_mlx *f)
{
	t_complex	d;

	d.r = f->xmax - f->xmin;
	d.i = f->ymax - f->ymin;
	if (keycode == ARROW_DOWN)
	{
		f->ymin -= d.i * 0.05;
		f->ymax -= d.i * 0.05;
	}
	else if (keycode == ARROW_UP)
	{
		f->ymin += d.i * 0.05;
		f->ymax += d.i * 0.05;
	}
	else if (keycode == ARROW_RIGHT)
	{
		f->xmin += d.r * 0.05;
		f->xmax += d.r * 0.05;
	}
	else if (keycode == ARROW_LEFT)
	{
		f->xmin -= d.r * 0.05;
		f->xmax -= d.r * 0.05;
	}
	display_fractal(f);
}

/*
 * this function drives the differents keyhook, for moving the fractal,
 * check the function upwards, for the c key (color change)
 * macos = 8
 * vm linux = 99
 * for the esc key (close window)
 * macos = 53
 * vm linux = 65307
*/

int	key_hook(int keycode, t_mlx  *f)
{
	if (keycode == ARROW_UP || keycode == ARROW_RIGHT || keycode == ARROW_LEFT
		|| keycode == ARROW_DOWN)
		move_fractal(keycode, f);
	else if (keycode == COLORKEY)
		color_change(f);
	else if (keycode == ESCKEY)
		close_window(keycode, f);
	return (0);
}
