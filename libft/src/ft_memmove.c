/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:59:54 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/04 14:29:55 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned const char	*src2;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (src == dst || len == 0)
		return (dst);
	else if (dst2 < src2)
		ft_memcpy(dst, src, len);
	else if (src2 < dst2)
	{
		while (len--)
		{
			dst2[len] = src2[len];
		}
	}
	return (dst);
}
