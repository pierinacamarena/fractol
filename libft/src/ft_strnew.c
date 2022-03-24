/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:31:35 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/01 00:26:15 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(newstr, '\0', size + 1);
	return (newstr);
}
