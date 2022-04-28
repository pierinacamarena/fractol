/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_alternative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandel_init(t_mlx *t)
{
	t->pixel.rr = 30 % (0x4F + 0x01);
	t->pixel.rg = 90 % (0x4F + 0x01);
	t->pixel.rb = 60 % (0x4F + 0x01);
	t->max_iter = 100;
	t->xmin = -2.0;
	t->xmax = 2.0;
	t->ymin = -1.0;
	t->ymax = 1.0;
	t->zoom = 100;
}

void	mandelbrot(t_mlx *t, int x, int y)
{
	int	i;

	t->c = convert_to_complex(x, y, t);
	t->z = convert_to_complex(x, y, t);
	i = 0;
	while ((i < t->max_iter) && (t->z.r * t->z.r + t->z.i * t->z.i < 4.0))
	{
		t->temp.r = t->z.r * t->z.r - t->z.i * t->z.i + t->c.r;
		t->temp.i = t->z.r * t->z.i * 2.0 + t->c.i;
		if (t->z.r == t->temp.r && t->z.i == t->temp.i)
		{
			i = t->max_iter;
			break ;
		}
		t->z.r = t->temp.r;
		t->z.i = t->temp.i;
		i++;
	}
	color(t, i);
	my_mlx_pixel_put(t, x, y);
}
