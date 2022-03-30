
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:26:31 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 18:51:30 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
basic_drawing.c
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* 
shapes.c
*/
void    draw_line_horizontal(t_data *img, int x, int y, int len, int color);
void    draw_line_vertical(t_data *img, int x, int y, int len, int color);
void    draw_line_slope_upwards(t_data *img, int x, int y, int len, int color);
void    draw_line_slope_downwards(t_data *img, int x, int y, int len, int color);
void    draw_square(t_data *img, int x, int y, int len, int color);
void    draw_triangle(t_data *img, int x, int y, int len, int color);
void    midpointcircle(t_data *img, int x, int y, int r, int color);

#endif
