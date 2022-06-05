/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	hooks(t_mlx *t)
{
	mlx_key_hook(t->win, key_hook, t);
	mlx_mouse_hook(t->win, mouse_hook, t);
	mlx_hook(t->win, 17, 0, close_window, t);
}

int	main(int ac, char **av)
{
	t_mlx	*t;

	if (ac < 2 || ac > 4 || ac == 3)
	{
		error_message(3, 'e');
		exit(0);
	}
	t = malloc(sizeof(t_mlx));
	if (!t)
		return (-1);
	t->param = param_check(av, ac, t);
	if (t->param == '\0')
	{
		error_message(3, 'e');
		free(t);
		exit(0);
	}
	init_image(t);
	if (t->param == 'm')
		init_borders_mandel(t);
	else if (t->param == 'j')
		init_borders_julia(t);
	else if (t->param == 'b')
		init_borders_burningship(t);
	hooks(t);
	draw(t);
	mlx_loop(t->mlx);
}
