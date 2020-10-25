/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiwithst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:26:35 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_atoiwithst(const char *str, t_cubed *st)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (str[st->i] == '\f' || str[st->i] == '\t' || str[st->i] == '\n' ||
			str[st->i] == '\r' || str[st->i] == '\v' || str[st->i] == ' ')
		st->i++;
	if (str[st->i] == '-' || str[st->i] == '+')
	{
		if (str[st->i] == '-')
			sign = -1;
		st->i++;
	}
	while (str[st->i] >= '0' && str[st->i] <= '9')
	{
		res *= 10;
		res += str[st->i] - '0';
		st->i++;
	}
	res *= sign;
	return (res);
}
