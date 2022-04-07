
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

# ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <complex.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

# define win_width 600
# define win_height 600

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_mandelalt
{
	int		maxN;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}				t_mandelalt;

typedef struct s_mandel
{
	int		maxN;
    double	min_r;
    double	max_r;
    double	min_i;
    double	max_i;
	double	cr;
	double	ci;
}				t_mandel;

typedef struct s_julia
{
	int		maxN;
    double	min_r;
    double	max_r;
    double	min_i;
    double	max_i;
	double	cr;
	double	ci;
}				t_julia;

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

/*
mandelbrot_set.c
*/
double	map_to_real(int x, int image_width, double min_r, double max_r);
double	map_to_imaginary(int y, int image_height, double min_i, double max_i);
int		findMandelbrot(double cr, double ci, int maxN);
void	init_mandelbrot(t_mandel *mandel);
void	mandelbrot_set(t_data *img, int x, int y);

/*
julia_set.c
*/
void    julia(t_mlx *tmlx, t_data *img);
void    init_julia(t_julia *julia);
int		find_julia(double cr, double ci, int x, int y, int maxN);
double	map_to_imaginary_julia(int y, int image_height, double min_i, double max_i);
double	map_to_real_julia(int x, int image_width, double min_r, double max_r);

/*
draw.c
*/
void		draw(t_mlx *tmlx, t_data *img);
t_complex	convert_to_complex(int x, int y, t_mandelalt *m);

/*
mandelbrot.c
*/
void    mandel_init(t_mandelalt *m);
void    mandelbrot(t_data *img, int x, int y);

#endif
