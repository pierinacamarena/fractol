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
** close the window when the ESC key is pressed
*/


int	close_window(int keycode, t_mlx *tmlx)
{
	if (keycode == ESCKEY)
		free(tmlx);
	exit(0);
}

/*
Driving the different keyboard hooks
*/

int	key_hook(int keycode, t_mlx *tmlx)
{
	if (keycode == ESCKEY)
		close_window(keycode, tmlx);
	return (0);
}
/*
int			motion_hook(int x, int y, t_3d *d)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && !d->julia_static)
	{
		d->julia.real = (x + d->offset.x) / (double)d->zoom + d->min.x;
		d->julia.imag = (y + d->offset.y) / (double)d->zoom + d->min.y;
		fractol(d);
	}
	return (1);
}
*/
