/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmapcar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:29:49 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/11 01:03:59 by sofiahechai      ###   ########lyon.fr   */
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

void	ft_configpos(t_cubed *st, char c)
{
	if (c == 'N')
	{
		st->dirx = 0;
		st->diry = -1;
	}
	if (c == 'S')
	{
		st->dirx = 0;
		st->diry = 1;
	}
	if (c == 'E')
	{
		st->dirx = 1;
		st->diry = 0;
	}
	if (c == 'W')
	{
		st->dirx = -1;
		st->diry = 0;
	}
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
			{
				ft_configpos(st, st->worldmap[x][y]);
				st->posx = (double)x + 0.5;
				st->posy = (double)y + 0.5;
				player++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (player != 1)
		return (0);
	return (1);
}