/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:55:10 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/01 00:12:53 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**splitstr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = 0;
	if (!(splitstr = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			splitstr[j++] = ft_substr(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	splitstr[j] = NULL;
	return (splitstr);
}
