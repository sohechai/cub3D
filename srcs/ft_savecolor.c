/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savecolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:57:53 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 19:02:19 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_savecolor(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'C')
		{
			st->i++;
			st->width = ft_atoiwithst(st->mapfile, st);
			if (st->mapfile[st->i] == ' ')
			{
				st->i++;
				st->height = ft_atoiwithst(st->mapfile, st);
			}
			else
				ft_putstr("Error, wrong resolution on your map file");
		}
		st->i++;
	}
}