/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:29:17 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	long	max;

	i = 0;
	max = n;
	if (max < 0)
	{
		ft_putchar_fd('-', fd);
		max *= -1;
	}
	if (max >= 10)
	{
		ft_putnbr_fd(max / 10, fd);
		ft_putchar_fd(max % 10 + '0', fd);
	}
	if (max < 10)
		ft_putchar_fd(max % 10 + '0', fd);
}
