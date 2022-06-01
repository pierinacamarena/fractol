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

void	init_image(t_mlx *t)
{
	t->pixel.rr = 30 % (0x4F + 0x01);
	t->pixel.rg = 90 % (0x4F + 0x01);
	t->pixel.rb = 60 % (0x4F + 0x01);
	t->w = 800;
	t->h = 800;
	t->zoom = 100;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->w, t->h, "fractol");
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->w, t->h);
	t->img_data = (unsigned char *)mlx_get_data_addr
		(t->img_ptr, &t->bpp, &t->size_line, &t->endian);
}

void	init_borders (t_mlx *t)
{
	if (t->id == 1 || t->id == 2)
	{
		t->xmin = -2.0;
		t->xmax = 2.0;
	}
	else if (t->id == 3)
	{
		t->xmin = -2.5;
		t->xmax = 1;
	}
	t->maxiter = 100;
	t->ymin = -2.0;
	t->ymax = t->ymin + (t->xmax - t->xmin) * t->h / t->w;
}
