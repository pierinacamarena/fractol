/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:40 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/21 18:25:54 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_image(t_mlx  *f)
{
	f->pixel.rr = 100 % (0x4F + 0x01);
	f->pixel.rg = 100 % (0x4F + 0x01);
	f->pixel.rb = 0 % (0x4F + 0x01);
	f->w = 800;
	f->h = 800;
	f->zoom = 100;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, f->w, f->h, "fractol");
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->w, f->h);
	f->img_data = (unsigned char *)mlx_get_data_addr
		(f->img_ptr, &f->bpp, &f->size_line, &f->endian);
}

static void	setup_x(t_mlx  *f)
{
	if (f->id == 1 || f->id == 2)
	{
		f->xmin = -2.0;
		f->xmax = 2.0;
	}
	else if (f->id == 3)
	{
		f->xmin = -2.5;
		f->xmax = 1;
	}
}

void	init_borders (t_mlx  *f)
{
	if (f->id == 1 || f->id == 2)
	{
		f->xmin = -2.0;
		f->xmax = 2.0;
	}
	else if (f->id == 3)
	{
		f->xmin = -2.5;
		f->xmax = 1;
	}
	f->maxiter = 100;
	setup_x(f);
	f->ymin = -2.0;
	f->ymax = f->ymin + (f->xmax - f->xmin) * f->h / f->w;
}
