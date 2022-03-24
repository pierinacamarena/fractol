/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:44:45 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:02:33 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char*)(s);
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return (&(s2[i]));
		i++;
	}
	return (NULL);
}
