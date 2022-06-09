/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:23:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_free_fractol(t_mlx *t)
{
	if (t->win && t->mlx)
	{
		mlx_destroy_window(t->mlx, t->win);
		t->win = NULL;
	}
	if (t->img && t->mlx)
	{
		mlx_destroy_image(t->mlx, t->img);
		t->img = NULL;
	}
	if (t->mlx)
	{
		mlx_destroy_display(t->mlx);
		free(t->mlx);
		t->mlx = NULL;
	}
    exit (0);
}

int	ft_finish(t_mlx *t)
{
    mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	mlx_destroy_window(t->mlx, t->win);
    mlx_destroy_display(t->mlx);
	free(t->mlx);
	free(t);
    ft_putstr_fd("project finished\n", 1);
	exit (0);
}