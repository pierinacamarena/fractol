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
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# define ESCKEY		65307
# define DOWN		65362
# define UP		65364
# define LEFT		65361
# define RIGHT		65363
# define COLORKEY	99

typedef struct s_complex
{
	double	r;
	double	i;
}				t_comp;

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
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	char		param;
	char		julia_id;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_iter;
	int			width;
	int			height;
	double		xscale;
	double		yscale;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		julia_x;
	double		julia_y;
	t_comp		c;
	t_comp		z;
	t_comp		temp;
	t_color		pixel;

}				t_mlx;

/*
fractol.c
*/
char	param_check(char **av, int ac, t_mlx *t);

/*
basic_drawing.c
*/
void	color(t_mlx *t, int i);
void	color_change(t_mlx *t);
void	my_mlx_pixel_put(t_mlx *tmlx, int x, int y);

/*
draw.c
*/
void	draw(t_mlx *t);
t_comp	convert_to_complex(int x, int y, t_mlx *t);
t_comp	julia_parameters(t_mlx *t);

/*
mandelbrot.c
*/
void	mandel_init(t_mlx *t);
void	mandelbrot(t_mlx *t, int x, int y);

/*
julia.c
*/
void	julia_init(t_mlx *t);
void	julia(t_mlx *t, int x, int y);

/*
hook.c
*/
int		close_window(int keycode, t_mlx *t);
int		key_hook(int keycode, t_mlx *t);
void	hook_calls(t_mlx *t);
void	move_fractal(int keycode, t_mlx *t);

/*
init.c
*/
void	init_image(t_mlx *t);
void	set_up(t_mlx *t);

/*
zoom.c
*/
int		mouse_hook(int button, int x, int y, t_mlx *t);

/*
burningship.c
*/
void	burningship_init(t_mlx *t);
void	burningship(t_mlx *t, int x, int y);

/*
param_helper.c
*/
char	param_julia_helper(char **av, t_mlx *t);
void	error_message(int i, char f);
char	param_julia_numbers(char **av, t_mlx *t);
#endif
