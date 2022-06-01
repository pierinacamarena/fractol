/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:27 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/14 13:25:31 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * subfunction that is handling differents hooks
 */

static void	hooks(t_mlx  *f)
{
	mlx_key_hook(f->win_ptr, key_hook, f);
	mlx_mouse_hook(f->win_ptr, mouse_hook, f);
	mlx_hook(f->win_ptr, 17, 0, close_window, f);
}

/*static int	take_arg(t_mlx  *f)
{
	if (!(ft_strcmp(f->argv[1], "mandelbrot")))
	{
		f->id = 1;
		if (f->argc > 2)
			return (0);
	}
	else if (!(ft_strcmp(f->argv[1], "julia")))
		f->id = 2;
	else if (!(ft_strcmp(f->argv[1], "burningship")))
	{
		f->id = 3;
		if (f->argc != 2)
			return (0);
	}
	else
		return (0);
	return (1);
}*/

/*
 * first main subfunction that is handling arguments
 */

/*static int	setup(t_mlx  *f, int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		return (0);
	f->id = 0;
	f->argv = argv;
	f->argc = argc;
	if (take_arg(f))
		return (1);
	return (0);
}*/

/*
 * Main function, allocating f and running the main subfunctions
 */

int	main(int ac, char **av)
{
	t_mlx	*t;

	if (ac < 2 || ac > 4)
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
	init_borders(t);
	hooks(t);
	display_fractal(t);
	mlx_loop(t->mlx_ptr);
}

/*int	main(int argc, char **argv)
{
	t_mlx 	*f;

	f = malloc(sizeof(t_mlx ));
	if (!f)
		return (0);
	if (setup(f, argc, argv))
	{
		init_image(f);
		init_mlx (f);
		hooks(f);
		display_fractal(f);
		mlx_loop(f->mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Wrong argument\t\t", 1);
		ft_putstr_fd("./fractol <julia, mandelbrot, burningship>", 1);
		ft_putstr_fd(" if julia : <float1> <float2>\n", 1);
		free(f);
		exit(0);
	}
	return (0);
}*/
