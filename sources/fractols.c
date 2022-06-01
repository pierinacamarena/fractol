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

static void	setup_fract(t_mlx *t)
{
	if (t->id == 1 || t->id == 3)
	{
		t->z.r = 0.0;
		t->z.i = 0.0;
	}
	if (t->id == 2)
	{
		t->z.i = t->ymin + t->y * t->yscale;
		t->z.r = t->xmin + t->x * t->xscale;
		t->c.r = t->j.r;
		t->c.i = t->j.i;
	}
}

void	julia(t_mlx *t)
{
	int		i;
	double	tmp;

	setup_fract(t);
	i = 0;
	while (((t->z.r * t->z.r) + (t->z.i * t->z.i) <= 4.0) && (i < t->maxiter))
	{
		tmp = (t->z.r * t->z.r) - (t->z.i * t->z.i) + t->c.r;
		t->z.i = 2 * t->z.r * t->z.i + t->c.i;
		t->z.r = tmp;
		i++;
	}
	colors(t, i);
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

void	burningship(t_mlx *t)
{
	int		i;
	double	temp;

	i = 0;
	setup_fract(t);
	while (((t->z.r * t->z.r) + (t->z.i * t->z.i) <= 4.0) && (i < t->maxiter))
	{
		temp = (t->z.r * t->z.r) - (t->z.i * t->z.i) + t->c.r;
		t->z.i = fabs(2 * t->z.r * t->z.i) + t->c.i;
		t->z.r = temp;
		i++;
	}
	colors(t, i);
}