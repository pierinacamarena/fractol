/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:59:40 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/01 00:23:55 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*nstr;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	nstr = ft_strnew(ft_strlen(s));
	if (!nstr)
		return (NULL);
	while (s[i])
	{
		nstr[i] = (f)(i, s[i]);
		i++;
	}
	return (nstr);
}
