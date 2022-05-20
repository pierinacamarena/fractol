/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:35:40 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:16:49 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst2;
	unsigned const char	*src2;
	size_t				l;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	l = 0;
	while (l < n)
	{
		dst2[l] = src2[l];
		if (dst2[l] == (unsigned char)c)
			return ((void *)(dst + l + 1));
		l++;
	}
	return (NULL);
}
