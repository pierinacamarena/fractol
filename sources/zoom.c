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

static void	apply_zoom(int x, int y, t_mlx *t)
{
	t_complex	mouse;
	double		inter;

	inter = 1.0 / t->zoom;
	mouse.r = x / (t->w / (t->xmax - t->xmin)) + t->xmin;
	mouse.i = y / (t->h / (t->ymax - t->ymin)) + t->ymin;
	t->xmin = interpolate(mouse.r, t->xmin, inter);
	t->ymin = interpolate(mouse.i, t->ymin, inter);
	t->xmax = interpolate(mouse.r, t->xmax, inter);
	t->ymax = interpolate(mouse.i, t->ymax, inter);
}

/*
 * taking as arguments the x and y position and the button pressed
 */

int	mouse_hook(int button, int x, int y, t_mlx *t)
{
	if (button == 4 || button == 1)
	{
		t->zoom = 0.80;
		apply_zoom(x, y, t);
		t->max_iter -= 5;
	}
	else if (button == 5 || button == 2)
	{
		t->zoom = 1.20;
		apply_zoom(x, y, t);
		t->max_iter += 5;
	}
	draw(t);
	return (0);
}
