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

int	main(void)
{
	t_mlx	tmlx;
	t_data	img;

	/*this will establish a connection to the correct graphical system and will 
        return a void * which holds the location of our current MLX instance.*/
    tmlx.mlx = mlx_init();

	tmlx.mlx_win = mlx_new_window(tmlx.mlx, win_width, win_height, "Hello world!");
	img.img = mlx_new_image(tmlx.mlx, win_width, win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mandelbrot(&tmlx, &img);
	mlx_loop(tmlx.mlx);
}
