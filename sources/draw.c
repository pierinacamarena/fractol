/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:16 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/08 21:28:19 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


/*
 * displaying the fractal throught an x y canvas
 */

void	draw(t_mlx *t)
{
	t->xscale = (t->xmax - t->xmin) / (t->w - 1);
	t->yscale = (t->ymax - t->ymin) / (t->h - 1);
	t->y = 0;
	while (t->y < t->h)
	{
		t->c.i = t->ymin + t->y * t->yscale;
		t->x = 0;
		while (t->x < t->w)
		{
			t->c.r = t->xmin + t->x * t->xscale;
			if (t->param == 'm')
				mandelbrot(t);
			else if (t->param == 'j')
				julia(t);
			else if (t->param == 'b')
				burningship(t);
			print_pixel(t);
			t->x++;
		}
		t->y++;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img_ptr, 0, 0);
}
