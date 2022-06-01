/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:07:17 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/08 21:37:48 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * this function calculate the new coordinate of one point after the zoom
 */

static double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

/*
 * here we calculate the 4 coordinate of the new window depending of the mouse
 * position after one scroll
 */

static void	apply_zoom(int x, int y, t_mlx  *f)
{
	t_complex	mouse;
	double		inter;

	inter = 1.0 / f->zoom;
	mouse.r = x / (f->w / (f->xmax - f->xmin)) + f->xmin;
	mouse.i = y / (f->h / (f->ymax - f->ymin)) + f->ymin;
	f->xmin = interpolate(mouse.r, f->xmin, inter);
	f->ymin = interpolate(mouse.i, f->ymin, inter);
	f->xmax = interpolate(mouse.r, f->xmax, inter);
	f->ymax = interpolate(mouse.i, f->ymax, inter);
}

/*
 * taking as arguments the x and y position and the button pressed
 */

int	mouse_hook(int button, int x, int y, t_mlx  *f)
{
	if (button == 4 || button == 1)
	{
		f->zoom = 0.80;
		apply_zoom(x, y, f);
		f->maxiter -= 5;
	}
	else if (button == 5 || button == 2)
	{
		f->zoom = 1.20;
		apply_zoom(x, y, f);
		f->maxiter += 5;
	}
	display_fractal(f);
	return (0);
}
