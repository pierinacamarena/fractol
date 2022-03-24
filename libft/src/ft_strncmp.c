/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:09:41 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 17:13:36 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1c;
	const unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1c[i] != '\0' && s2c[i] != '\0' && s1c[i] == s2c[i] && i < (n - 1))
		i++;
	return (s1c[i] - s2c[i]);
}
