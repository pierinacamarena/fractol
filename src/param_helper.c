/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.tr       */
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
	else if (f == 'e' && i == 3)
	{
		ft_putstr_fd("launch the program like this:\n", 1);
		ft_putstr_fd("./fractol {mandelbrot/julia/burningship}\n", 1);
		ft_putstr_fd("if julia -> ./fractol julia (letter from a-f)\n", 1);
	}
}

char	param_julia_helper(char **av, t_mlx *t)
{
	char	dest;

	dest = '\0';
	if ((av[2][0] == 'a' || av[2][0] == 'b' || av[2][0] == 'c' \
			|| av[2][0] == 'd' || av[2][0] == 'e' \
			|| av[2][0] == 'f') && (av[2][1] == '\0'))
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
