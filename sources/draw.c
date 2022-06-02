/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw(t_mlx *t)
{
	t->xscale = (t->xmax - t->xmin) / (t->w - 1);
	t->yscale = (t->ymax - t->ymin) / (t->h - 1);
	t->y = 0;
	while (t->y < t->h)
	{
		t->c.i = t->ymin + t->y * t->yscale;
		t->x = 0;
		while (t->x < t->w)
		{
			t->c.r = t->xmin + t->x * t->xscale;
			if (t->param == 'm')
				mandelbrot(t);
			else if (t->param == 'j')
				julia(t);
			else if (t->param == 'b')
				burningship(t);
			print_pixel(t);
			t->x++;
		}
		t->y++;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img_ptr, 0, 0);
}

void	julia(t_mlx *t)
{
	int		i;
	double	tmp;

	t->z.i = t->ymin + t->y * t->yscale;
	t->z.r = t->xmin + t->x * t->xscale;
	t->c.r = t->j.r;
	t->c.i = t->j.i;
	i = 0;
	while (((t->z.r * t->z.r) + (t->z.i * t->z.i) <= 4.0) && (i < t->max_iter))
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
	t->z.r = 0.0;
	t->z.i = 0.0;
	while ((i < t->max_iter) && (t->z.r * t->z.r + t->z.i * t->z.i < 4.0))
	{
		t->temp.r = t->z.r * t->z.r - t->z.i * t->z.i + t->c.r;
		t->temp.i = t->z.r * t->z.i * 2.0 + t->c.i;
		if (t->z.r == t->temp.r && t->z.i == t->temp.i)
		{
			i = t->max_iter;
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
	t->z.r = 0.0;
	t->z.i = 0.0;
	while (((t->z.r * t->z.r) + (t->z.i * t->z.i) <= 4.0) && (i < t->max_iter))
	{
		temp = (t->z.r * t->z.r) - (t->z.i * t->z.i) + t->c.r;
		t->z.i = fabs(2 * t->z.r * t->z.i) + t->c.i;
		t->z.r = temp;
		i++;
	}
	colors(t, i);
}
