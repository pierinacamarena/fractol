/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:58 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/08 21:28:55 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	colors(t_mlx *t, int i)
{
	if (i == t->maxiter)
	{
		t->pixel.r = 0.0;
		t->pixel.g = 0.0;
		t->pixel.b = 0.0;
	}
	else
	{
		t->pixel.r = (t->pixel.rr * i) * 255 / t->maxiter;
		t->pixel.g = (t->pixel.rg * i) * 255 / t->maxiter;
		t->pixel.b = (t->pixel.rb * i) * 255 / t->maxiter;
	}
}

void	print_pixel(t_mlx *t)
{
	int	i;

	i = (t->x * t->bpp / 8 + (t->y * t->size_line));
	t->img_data[i + 0] = t->pixel.r;
	t->img_data[i + 1] = t->pixel.g;
	t->img_data[i + 2] = t->pixel.b;
}
