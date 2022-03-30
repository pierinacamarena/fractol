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
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	/*this will establish a connection to the correct graphical system and will 
        return a void * which holds the location of our current MLX instance.*/
    mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	draw_square(&img, 500, 500, 100, 0x008B8B);
	draw_triangle(&img, 200, 200, 300, 0x0000FF00);
	midpointcircle(&img, 60, 60, 30, 0x000000FF);
	mlx_loop(mlx);
}
