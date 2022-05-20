/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:57:30 by pcamaren          #+#    #+#             */
/*   Updated: 2022/05/20 17:41:43 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_neg_itoa(char *numstr, int n, int len)
{
	numstr[0] = '-';
	n = -n;
	while (n > 0 && len > 1)
	{
		numstr[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (numstr);
}

char	*itoa_dummy(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (NULL);
}

char	*ft_itoa(int n)
{
	int		len;
	int		mainlen;
	char	*numstr;

	if (n == -2147483648 || n == 0)
		return (itoa_dummy(n));
	len = ft_intsize(n);
	mainlen = ft_intsize(n);
	numstr = ft_strnew(len);
	if (!numstr)
		return (NULL);
	if (n < 0)
		ft_neg_itoa(numstr, n, len);
	else
	{
		while (n > 0 && len > 0)
		{
			numstr[len - 1] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	numstr[mainlen] = '\0';
	return (numstr);
}
