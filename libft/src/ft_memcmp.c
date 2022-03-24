/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:57:39 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:06:43 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1a;
	unsigned char *s2a;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	while (n--)
	{
		if ((unsigned char)*s1a != (unsigned char)*s2a)
			return ((unsigned char)*s1a - (unsigned char)*s2a);
		if (n)
		{
			s1a++;
			s2a++;
		}
	}
	return (0);
}
