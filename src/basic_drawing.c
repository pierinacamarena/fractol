/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(t_mlx *t, int i)
{
	if (i == t->max_iter)
	{
		t->pixel.r = 0.0;
		t->pixel.g = 0.0;
		t->pixel.b = 0.0;
	}
	else
	{
		t->pixel.r = (t->pixel.rr * i) * 255 / t->max_iter;
		t->pixel.g = (t->pixel.rg * i) * 255 / t->max_iter;
		t->pixel.b = (t->pixel.rb * i) * 255 / t->max_iter;
	}
}

void	my_mlx_pixel_put(t_mlx *t, int x, int y)
{
	int	i;

	i = (x * t->bits_per_pixel / 8 + (y * t->line_length));
	t->addr[i + 0] = t->pixel.r;
	t->addr[i + 1] = t->pixel.g;
	t->addr[i + 2] = t->pixel.b;
}

void	color_change(t_mlx *t)
{
	t->pixel.rr = t->pixel.rr + 1 % 255;
	t->pixel.rb = t->pixel.rb + 10 % 255;
	t->pixel.rg = t->pixel.rg + 100 % 255;
	draw(t);
}
