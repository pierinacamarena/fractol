/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:16:07 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:13:03 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dlen;
	size_t			slen;
	unsigned int	i;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (slen + dstsize);
	while (dst[i] != '\0' && i < (dstsize - 1))
		i++;
	while (*src && i < (dstsize - 1))
		dst[i++] = *src++;
	dst[i] = '\0';
	return (slen + dlen);
}
