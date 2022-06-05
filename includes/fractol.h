/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
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
# include <complex.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# define ESC		65307
# define DOWN		65362
# define UP		65364
# define LEFT		65361
# define RIGHT		65363
# define COLOR	99

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		rr;
	int		rb;
	int		rg;
}				t_color;

typedef struct s_mlx
{
	char			param;
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				h;
	int				w;
	int				x;
	int				y;
	t_color			pixel;
	t_complex		c;
	t_complex		z;
	t_complex		j;
	t_complex		temp;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			xscale;
	double			yscale;
	int				max_iter;
	double			zoom;
}				t_mlx;

/* draw */
void	draw(t_mlx *t);
void	mandelbrot(t_mlx *t);
void	julia(t_mlx *t);
void	burningship(t_mlx *t);

/* movements */
int		mouse_hook(int button, int x, int y, t_mlx *t);

/* key controls */
int		key_hook(int keycode, t_mlx *t);
int		close_window(int keycode, t_mlx *t);

/* init */
void	init_image(t_mlx *t);
void	init_borders_mandel(t_mlx *t);
void	init_borders_julia(t_mlx *t);
void	init_borders_burningship(t_mlx *t);

/* output */
void	print_pixel(t_mlx *t);
void	colors(t_mlx *t, int i);

/* parsing */
char	param_julia_numbers(char **av, t_mlx *t);
char	param_julia_helper(char **av, t_mlx *t);
void	error_message(int i, char f);
char	param_check(char **av, int ac, t_mlx *t);
int		check_double(char *double_str);

#endif
