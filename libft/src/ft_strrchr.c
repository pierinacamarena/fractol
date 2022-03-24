/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:25:16 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:13:30 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	len = ft_strlen(s);
	s += len;
	while (len > -1)
	{
		if (*s == c)
			return ((char *)s);
		len--;
		s--;
	}
	return (NULL);
}
