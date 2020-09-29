/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmapcar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:29:49 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/29 00:37:46 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_checkmapcar(t_cubed *st)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (st->worldmap[x] != 0)
	{
		while (st->worldmap[x][y] != '\0')
		{
			if(st->worldmap[x][y] != '0' && st->worldmap[x][y] != '1' &&
				st->worldmap[x][y] != '2' && st->worldmap[x][y] != 'N' &&
				st->worldmap[x][y] != 'S' && st->worldmap[x][y] != 'E' &&
				st->worldmap[x][y] != 'W' && st->worldmap[x][y] != 'X')
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int		ft_checkplayer(t_cubed *st)
{
	int		x;
	int		y;
	int		player;

	x = 0;
	y = 0;
	player = 0;
	while (st->worldmap[x] != 0)
	{
		while (st->worldmap[x][y] != '\0')
		{
			if(st->worldmap[x][y] == 'N' || st->worldmap[x][y] == 'S' ||
				st->worldmap[x][y] == 'E' || st->worldmap[x][y] == 'W')
				player++;
			y++;
		}
		y = 0;
		x++;
	}
	if (player != 1)
		return (0);
	return (1);
}