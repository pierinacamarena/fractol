/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_pixel(t_mlx *t)
{
	int	i;

	i = (t->x * t->bpp / 8 + (t->y * t->size_line));
	t->img_data[i + 0] = t->pixel.r;
	t->img_data[i + 1] = t->pixel.g;
	t->img_data[i + 2] = t->pixel.b;
}

void	colors(t_mlx *t, int i)
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
