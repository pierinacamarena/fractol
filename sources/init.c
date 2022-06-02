/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_image(t_mlx *t)
{
	t->pixel.rr = 30 % (0x4F + 0x01);
	t->pixel.rg = 90 % (0x4F + 0x01);
	t->pixel.rb = 60 % (0x4F + 0x01);
	t->w = 800;
	t->h = 800;
	t->zoom = 100;
	t->mlx_ptr = mlx_init();
	if (t->param == 'm')
		t->win_ptr = mlx_new_window(t->mlx_ptr, t->w, t->h, "mandelbrot");
	else if (t->param == 'j')
		t->win_ptr = mlx_new_window(t->mlx_ptr, t->w, t->h, "julia");
	else if (t->param == 'b')
		t->win_ptr = mlx_new_window(t->mlx_ptr, t->w, t->h, "burningship");
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->w, t->h);
	t->img_data = (unsigned char *)mlx_get_data_addr
		(t->img_ptr, &t->bpp, &t->size_line, &t->endian);
}

void	init_borders_mandel_julia(t_mlx *t)
{
	t->xmin = -2.0;
	t->xmax = 2.0;
	t->max_iter = 100;
	t->ymin = -2.0;
	t->ymax = t->ymin + (t->xmax - t->xmin) * t->h / t->w;
}

void	init_borders_burningship(t_mlx *t)
{
	t->xmin = -2.5;
	t->xmax = 1;
	t->max_iter = 100;
	t->ymin = -2.0;
	t->ymax = t->ymin + (t->xmax - t->xmin) * t->h / t->w;
}
