/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** hook functions
*/

void	hook_calls(t_mlx *t)
{
	mlx_key_hook(t->mlx_win, key_hook, t);
	mlx_mouse_hook(t->mlx_win, mouse_hook, t);
	mlx_hook(t->mlx_win, 17, 0, close_window, t);
}

/*
** close the window when the ESC key is pressed
*/

int	close_window(int keycode, t_mlx *t)
{
	if (keycode == ESCKEY)
	{
		mlx_clear_window(t->mlx, t->mlx_win);
		mlx_destroy_image(t->mlx, t->img);
		mlx_destroy_window(t->mlx, t->mlx_win);
		mlx_destroy_display(t->mlx);
		free(t->mlx);
		free(t);
	}
	exit(0);
}

/*
** Driving the different keyboard hooks
*/

int	key_hook(int keycode, t_mlx *t)
{
	if (keycode == ESCKEY)
		close_window(keycode, t);
	else if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
		move_fractal(keycode, t);
	else if (keycode == COLORKEY)
		color_change(t);
	return (0);
}

/*
** Moving the fractal
*/

void	move_fractal(int keycode, t_mlx *t)
{
	t_comp	r;

	r.r = t->xmax - t->xmin;
	r.i = t->ymax - t->ymin;
	if (keycode == DOWN)
	{
		t->ymin -= r.i * 0.05;
		t->ymax -= r.i * 0.05;
	}
	else if (keycode == UP)
	{
		t->ymin += r.i * 0.05;
		t->ymax += r.i * 0.05;
	}
	else if (keycode == RIGHT)
	{
		t->xmin += r.r * 0.05;
		t->xmax += r.r * 0.05;
	}
	else if (keycode == LEFT)
	{
		t->xmin -= r.r * 0.05;
		t->xmax -= r.r * 0.05;
	}
	draw(t);
}
