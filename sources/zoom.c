/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

static void	zooming(int x, int y, t_mlx *t)
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

int	mouse_hook(int button, int x, int y, t_mlx *t)
{
	if (button == 4 || button == 1)
	{
		t->zoom = 0.80;
		zooming(x, y, t);
		t->max_iter -= 5;
	}
	else if (button == 5 || button == 2)
	{
		t->zoom = 1.20;
		zooming(x, y, t);
		t->max_iter += 5;
	}
	draw(t);
	return (0);
}
