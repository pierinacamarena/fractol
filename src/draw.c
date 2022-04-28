/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw(t_mlx *t)
{
	int	x;
	int	y;

	t->yscale = (t->xmax - t->xmin) / (WIDTH - 1);
	t->xscale = (t->ymax - t->ymin) / (HEIGHT - 1);
	y = 0;
	t->c.i = t->ymin + y * t->yscale;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			t->c.r = t->xmin + x * t->xscale;
			if (t->param == 'm')
				mandelbrot(t, x, y);
			else if (t->param == 'j')
				julia(t, x, y);
			else if (t->param == 'b')
				burningship(t, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(t->mlx, t->mlx_win, t->img, 0, 0);
}

t_complex	convert_to_complex(int x, int y, t_mlx *t)
{
	t_complex	c;
	double		range_x;
	double		range_y;

	range_x = t->xmax - t->xmin;
	range_y = t->ymax - t->ymin;
	c.r = ((double)x * (range_x / WIDTH) + t->xmin);
	c.i = ((double)y * (range_y / HEIGHT) + t->ymin);
	return (c);
}
