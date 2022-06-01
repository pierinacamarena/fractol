/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alangloi <alangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:30:33 by alangloi          #+#    #+#             */
/*   Updated: 2021/09/27 15:06:31 by alangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	str_digit(char *new)
{
	char	*str;

	str = new;
	if (!str)
		return (0);
	if (str[0] == '0' || (str[0] == '0' && str[1] == '.' && str[2] == '0'))
		return (1);
	if (ft_atof(str) > INT_MAX || ft_atof(str) < INT_MIN
		|| ft_atof(str) == 0.0)
		return (0);
	return (1);
}
