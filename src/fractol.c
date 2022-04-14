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

char	param_check(char *fractal)
{
	char	dest;
	
	if (!(ft_strcmp(fractal, "julia")))
		dest = fractal[0];
	else if (!(ft_strcmp(fractal, "mandelbrot")))
		dest = fractal[0];
	else
		dest = '\0';
	return (dest);
}

int	main(int ac, char **av)
{
	t_mlx	*tmlx;
	char	fractal;

	tmlx = malloc(sizeof(t_mlx));
	fractal = param_check(av[1]);
    tmlx->mlx = mlx_init();
	if (fractal == '\0' || ac < 2)
		{
			ft_putstr_fd("Wrong arguments :(\n", 1);
			exit(0);
		}
	if (fractal == 'm')
		tmlx->mlx_win = mlx_new_window(tmlx->mlx, win_width, win_height, "Mandelbrot");
	else if (fractal == 'j')
		tmlx->mlx_win = mlx_new_window(tmlx->mlx, win_width, win_height, "Julia");
	tmlx->img = mlx_new_image(tmlx->mlx, win_width, win_height);
	tmlx->addr = mlx_get_data_addr(tmlx->img, &tmlx->bits_per_pixel, &tmlx->line_length, &tmlx->endian);
	draw(tmlx, fractal);
	mlx_key_hook(tmlx->mlx_win, key_hook, &tmlx);
	mlx_hook(tmlx->mlx_win, 17, 0, close_window, &tmlx);
	mlx_loop(tmlx->mlx);
}
