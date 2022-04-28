/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningship_init(t_mlx *t)
{
	t->pixel.rr = 30 % (0x4F + 0x01);
	t->pixel.rg = 90 % (0x4F + 0x01);
	t->pixel.rb = 10 % (0x4F + 0x01);
	t->max_iter = 100;
	t->xmin = -2.5;
	t->xmax = 1.0;
	t->ymin = -2.0;
	t->ymax = 1.0;
	t->zoom = 100;
}

void	burningship(t_mlx *t, int x, int y)
{
	int		i;
	double	temp;

	i = 0;
	t->c = convert_to_complex(x, y, t);
	t->z = convert_to_complex(x, y, t);
	while (((t->z.r * t->z.r) + (t->z.i * t->z.i) <= 4.0) && (i < t->max_iter))
	{
		temp = (t->z.r * t->z.r) - (t->z.i * t->z.i) + t->c.r;
		t->z.i = fabs(2 * t->z.r * t->z.i) + t->c.i;
		t->z.r = temp;
		i++;
	}
	color(t, i);
	my_mlx_pixel_put(t, x, y);
}
