/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_mlx *t)
{
	t->pixel.rr = 70 % (0x4F + 0x01);
	t->pixel.rg = 90 % (0x4F + 0x01);
	t->pixel.rb = 0 % (0x4F + 0x01);
	t->max_iter = 100;
	t->xmin = -2.0;
	t->xmax = 2.0;
	t->ymin = -2.0;
	t->ymax = 2.0;
	t->zoom = 100;
}

t_complex	julia_parameters_helper(t_mlx *t)
{
	t_complex	c;

	if (t->julia_id == 'd')
	{
		c.i = 0.45;
		c.r = 0.1428;
	}
	if (t->julia_id == 'e')
	{
		c.i = 0.285;
		c.r = 0.01;
	}
	if (t->julia_id == 'f')
	{
		c.i = -0.12;
		c.r = -0.77;
	}
	return (c);
}

t_complex	julia_parameters(t_mlx *t)
{
	t_complex	c;

	if (t->julia_id == 'a')
	{
		c.r = -0.7269;
		c.i = 0.1889;
	}
	else if (t->julia_id == 'b')
	{
		c.r = -0.8;
		c.i = 0.156;
	}
	else if (t->julia_id == 'c')
	{
		c.i = -0.835;
		c.r = -0.2321;
	}
	else
		c = julia_parameters_helper(t);
	return (c);
}

void	julia(t_mlx *t, int x, int y)
{
	int	i;

	t->z = convert_to_complex(x, y, t);
	t->c = julia_parameters(t);
	i = 0;
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
	color(t, i);
	my_mlx_pixel_put(t, x, y);
}
