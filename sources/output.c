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

void	colors(t_mlx  *f, int i)
{
	if (i == f->maxiter)
	{
		f->pixel.r = 0.0;
		f->pixel.g = 0.0;
		f->pixel.b = 0.0;
	}
	else
	{
		f->pixel.r = (f->pixel.rr * i) * 255 / f->maxiter;
		f->pixel.g = (f->pixel.rg * i) * 255 / f->maxiter;
		f->pixel.b = (f->pixel.rb * i) * 255 / f->maxiter;
	}
}

void	print_pixel(t_mlx  *f)
{
	int	i;

	i = (f->x * f->bpp / 8 + (f->y * f->size_line));
	f->img_data[i + 0] = f->pixel.r;
	f->img_data[i + 1] = f->pixel.g;
	f->img_data[i + 2] = f->pixel.b;
}
