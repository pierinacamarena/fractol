/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:24:03 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/26 22:14:56 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_power(int base, unsigned int power)
{
	int	result;
	int	temp;

	result = 1;
	if (power == 0)
		return (result);
	temp = ft_power(base, power / 2);
	if (power % 2 == 0)
		return (temp * temp);
	else
		return (base * temp * temp);
}
