/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:14:56 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:11:35 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (c == *(s + 1))
			return ((char *)s + 1);
		else if (c == *(s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
