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

void	display_fractal(t_mlx  *f)
{
	f->xscale = (f->xmax - f->xmin) / (f->w - 1);
	f->yscale = (f->ymax - f->ymin) / (f->h - 1);
	f->y = 0;
	while (f->y < f->h)
	{
		f->c.i = f->ymin + f->y * f->yscale;
		f->x = 0;
		while (f->x < f->w)
		{
			f->c.r = f->xmin + f->x * f->xscale;
			if (f->id == 1)
				mandelbrot(f);
			else
				fractal_set(f);
			print_pixel(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
