/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	param(char *fractal)
{
	char	dest;
	
	dest = fractal[0];
	return (dest);
}

int	main(int ac, char **av)
{
	t_mlx	tmlx;
	t_data	img;
	char	fractal;

	if (ac < 2)
		return (0);
	fractal = param(av[1]);
    tmlx.mlx = mlx_init();
	if (fractal == 'm')
		tmlx.mlx_win = mlx_new_window(tmlx.mlx, win_width, win_height, "Mandelbrot");
	else if (fractal == 'j')
		tmlx.mlx_win = mlx_new_window(tmlx.mlx, win_width, win_height, "Julia");
	img.img = mlx_new_image(tmlx.mlx, win_width, win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw(&tmlx, &img, fractal);
	mlx_key_hook(tmlx.mlx_win, key_hook, &tmlx);
	mlx_loop(tmlx.mlx);
}
