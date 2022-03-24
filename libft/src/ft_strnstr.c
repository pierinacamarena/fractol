/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:36:29 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:15:11 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			i = len;
			s1 = (char *)haystack + 1;
			s2 = (char *)needle + 1;
			while (i-- && *s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (!*s2)
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
