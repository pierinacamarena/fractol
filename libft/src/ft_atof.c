/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:12:29 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:20:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static double	ft_atoi_decimal(char *str)
{
	double	nb;
	int		power;

	nb = 0;
	power = 0;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			nb = (nb * 10) + (*str - '0');
			str++;
			power++;
		}
		if (nb < 0)
			nb = -nb;
	}
	nb = nb / ft_power(10, power);
	return (nb);
}

double	ft_atof(char *s)
{
	double	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb = (nb * 10) + ((*s++) - '0');
	}
	nb = nb + ft_atoi_decimal(s);
	return (nb * sign);
}
