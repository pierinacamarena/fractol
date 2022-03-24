/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:41:27 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 16:55:40 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	*b2;
	unsigned char	c2;

	b2 = b;
	c2 = c;
	n = 0;
	while (n < len)
	{
		b2[n] = c2;
		n++;
	}
	return (b);
}
