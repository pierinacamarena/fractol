/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_up(t_mlx *t)
{
	t->width = 1370;
	t->height = 700;
	if (t->param == 'm')
		mandel_init(t);
	else if (t->param == 'j')
		julia_init(t);
	else if (t->param == 'b')
		burningship_init(t);
}

void	init_image(t_mlx *t)
{
	t->mlx = mlx_init();
	if (t->param == 'm')
	{
		t->mlx_win = mlx_new_window(t->mlx, \
				t->width, t->height, "Mandelbrot");
	}
	else if (t->param == 'j')
	{
		t->mlx_win = mlx_new_window(t->mlx, \
				t->width, t->height, "Julia");
	}
	if (t->param == 'b')
	{
		t->mlx_win = mlx_new_window(t->mlx, \
		t->width, t->height, "Burningship");
	}
	t->img = mlx_new_image(t->mlx, t->width, t->height);
	t->addr = mlx_get_data_addr(t->img, \
			&t->bits_per_pixel, &t->line_length, &t->endian);
}
