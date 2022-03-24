/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:34:49 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:12 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dst2;
	const char		*src2;
	size_t			len;

	if (dst == src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (char *)src;
	len = 0;
	while (len < n)
	{
		dst2[len] = src2[len];
		len++;
	}
	return ((void *)dst);
}
