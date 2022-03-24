/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 23:40:30 by pcamaren          #+#    #+#             */
/*   Updated: 2019/12/03 23:41:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_frontstr(char const *s1, char const *set, int front)
{
	int j;
	int k;

	k = ft_strlen(set);
	while (s1[front])
	{
		j = 0;
		while (set[j] && s1[front] != set[j])
			j++;
		if (s1[front] == set[j] && j < k)
			front++;
		else
			break ;
	}
	return (front);
}

static int	ft_backstr(char const *s1, char const *set, int back, int front)
{
	int j;
	int k;

	j = 0;
	k = ft_strlen(set);
	while (s1[back] && back > front)
	{
		j = 0;
		while (set[j] && s1[back] != set[j])
			j++;
		if (s1[back] == set[j] && j < k)
			back--;
		else
			break ;
	}
	return (back);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		front;
	int		back;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	if (!*s1)
		return ((char *)s1);
	front = 0;
	back = ft_strlen(s1) - 1;
	i = 0;
	front = ft_frontstr(s1, set, front);
	back = ft_backstr(s1, set, back, front);
	len = back - front + 1;
	if (!(strtrim = ft_strnew(len)))
		return (NULL);
	while (len--)
		strtrim[i++] = s1[front++];
	return (strtrim);
}
