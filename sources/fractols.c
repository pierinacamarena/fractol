/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * setup the variables of the differents fractals
 */

static void	setup_fract(t_mlx  *f)
{
	if (f->id == 1 || f->id == 3)
	{
		f->z.r = 0.0;
		f->z.i = 0.0;
	}
	if (f->id == 2)
	{
		f->z.i = f->ymin + f->y * f->yscale;
		f->z.r = f->xmin + f->x * f->xscale;
		f->c.r = f->j.r;
		f->c.i = f->j.i;
	}
}

/*
 * launching the algorithm of the fractal
 */

void	fractal_set(t_mlx  *f)
{
	int		i;
	double	tmp;

	setup_fract(f);
	i = 0;
	while (((f->z.r * f->z.r) + (f->z.i * f->z.i) <= 4.0) && (i < f->maxiter))
	{
		tmp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
		if (f->id == 3)
			f->z.i = fabs(2 * f->z.r * f->z.i) + f->c.i;
		else
			f->z.i = 2 * f->z.r * f->z.i + f->c.i;
		f->z.r = tmp;
		i++;
	}
	colors(f, i);
}

void	mandelbrot(t_mlx *t)
{
	int	i;

	i = 0;
	setup_fract(t);
	while ((i < t->maxiter) && (t->z.r * t->z.r + t->z.i * t->z.i < 4.0))
	{
		t->temp.r = t->z.r * t->z.r - t->z.i * t->z.i + t->c.r;
		t->temp.i = t->z.r * t->z.i * 2.0 + t->c.i;
		if (t->z.r == t->temp.r && t->z.i == t->temp.i)
		{
			i = t->maxiter;
			break ;
		}
		t->z.r = t->temp.r;
		t->z.i = t->temp.i;
		i++;
	}
	colors(t, i);
}