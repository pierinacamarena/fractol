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

void	error_message(int i, char f)
{
	if (f == 'j')
	{
		if (i == 1)
			ft_putstr_fd("Wrong arguments :(\n", 1);
		else if (i == 2)
			ft_putstr_fd("You need to add more one more argument :(\n", 1);
		ft_putstr_fd("launch the program like this: ", 1);
		ft_putstr_fd("/fractol julia (a letter from a-f)\n", 1);
		ft_putstr_fd("example: ./fractol julia d \n", 1);
	}
	else if (f == 'm')
	{
		if (i == 1)
		{
			ft_putstr_fd("you are launching the ", 1);
			ft_putstr_fd("program with too many arguments:(\n", 1);
		}
		ft_putstr_fd("launch the program like this: ./fractol mandelbrot\n", 1);
	}
}

char	param_julia_helper(char **av, t_mlx *t)
{
	char	dest;

	dest = '\0';
	if (av[2][0] == 'a' || av[2][0] == 'b' || av[2][0] == 'c' \
			|| av[2][0] == 'd' || av[2][0] == 'e' || av[2][0] == 'f')
	{
		dest = 'j';
		t->julia_id = av[2][0];
	}
	else
	{
		error_message(1, 'j');
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
		else if (ac == 2)
		{
			error_message(2, 'j');
			dest = '\0';
		}
	}
	else if (!(ft_strcmp(av[1], "mandelbrot")))
	{
		if (ac == 2)
			dest = 'm';
		if (ac > 2)
		{
			error_message(1, 'm');
			dest = '\0';
		}
	}
	return (dest);
}

int	main(int ac, char **av)
{
	t_mlx	*t;

	t = malloc(sizeof(t_mlx));
	t->param = param_check(av, ac, t);
	if (t->param == '\0' || ac < 2)
	{
		ft_putstr_fd("Wrong arguments :(\n", 1);
		exit(0);
	}
	set_up(t);
	init_image(t);
	hook_calls(t);
	draw(t);
	mlx_loop(t->mlx);
}
