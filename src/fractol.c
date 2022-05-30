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

char	param_burningship(int ac)
{
	char	dest;

	dest = '\0';
	if (ac == 2)
		dest = 'b';
	else if (ac > 2)
	{
		error_message(1, 'm');
		dest = '\0';
	}
	return (dest);
}

char	param_mandelbrot(int ac)
{
	char	dest;

	dest = '\0';
	if (ac == 2)
		dest = 'm';
	else if (ac > 2)
	{
		error_message(1, 'm');
		dest = '\0';
	}
	return (dest);
}

char	param_check(char **av, int ac, t_mlx *t)
{
	char	dest;

	dest = '\0';
	if (!(ft_strcmp(av[1], "julia")))
	{
		if (ac == 3)
			dest = param_julia_helper(av, t);
		else if (ac == 4)
			dest = param_julia_numbers(av, t);
		else if (ac == 2)
		{
			error_message(2, 'j');
			dest = '\0';
		}
	}
	else if (!(ft_strcmp(av[1], "mandelbrot")))
		dest = param_mandelbrot(ac);
	else if (!(ft_strcmp(av[1], "burningship")))
		dest = param_burningship(ac);
	return (dest);
}

int	main(int ac, char **av)
{
	t_mlx	*t;

	if (ac < 2)
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
	set_up(t);
	init_image(t);
	hook_calls(t);
	draw(t);
	mlx_loop(t->mlx);
}
