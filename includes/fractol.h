
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

# define win_width 1370
# define win_height 700
# define ESCKEY		65307

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct	s_setup
{
	int		maxN;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	char	*fractal;
}				t_setup;

/*
fractol.c
*/

char	param_check(char *fractal);

/*
basic_drawing.c
*/
void	my_mlx_pixel_put(t_mlx *tmlx, int x, int y, int color);

/*
draw.c
*/
void		draw(t_mlx *tmlx, char param);
t_complex	convert_to_complex(int x, int y, t_setup *m);

/*
mandelbrot.c
*/
void    mandel_init(t_setup *m);
void    mandelbrot(t_mlx *tmlx, int x, int y);

/*
julia.c
*/
void    julia_init(t_setup *j);
void    julia(t_mlx *tmlx, int x, int y);

/*
hook.c
*/
int	close_window(int keycode, t_mlx *tmlx);
int	key_hook(int keycode, t_mlx *tmlx);

#endif
