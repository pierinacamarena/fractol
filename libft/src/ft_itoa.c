/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:57:30 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 21:33:40 by pcamaren         ###   ########.fr       */
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

char		*ft_itoa(int n)
{
	int		len;
	int		mainlen;
	char	*numstr;

	if (n == 0 || n == -2147483648)
		return (ft_strdup(!n ? "0" : "-2147483648"));
	len = ft_intsize(n);
	mainlen = ft_intsize(n);
	if (!(numstr = ft_strnew(len)))
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
