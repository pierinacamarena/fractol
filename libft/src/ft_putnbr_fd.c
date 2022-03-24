/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:04:06 by pcamaren          #+#    #+#             */
/*   Updated: 2019/11/19 16:50:39 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putneg_fd(unsigned int n, int fd)
{
	if (n / 10 != 0)
		ft_putneg_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_putneg_fd((unsigned int)n, fd);
}
