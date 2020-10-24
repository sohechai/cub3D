/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmapcar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:29:49 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 21:06:11 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void        ft_setdata(t_cubed *st)
{
	if (st->diry == -1.0 && st->dirx == 0.0)
	{
		st->planex = 0.66;
		st->planey = 0;
	}
	if (st->dirx == 0.0 && st->diry == 1.0)
	{
		st->planex = -0.66;
		st->planey = 0;
	}
	if (st->dirx == 1.0 && st->diry == 0.0)
	{
		st->planex = 0;
		st->planey = 0.66;
	}
	if (st->dirx == -1.0 && st->diry == 0.0)
	{
		st->planex = 0;
		st->planey = -0.66;
	}
}

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
	ft_setdata(st);
}

int		ft_checkplayer(t_cubed *st)
{
	int		x;
	int		y;
	int		player;

	x = 0;
	y = 0;
	player = 0;
	while (st->worldmap[y] != 0)
	{
		while (st->worldmap[y][x] != '\0')
		{
			if(st->worldmap[y][x] == 'N' || st->worldmap[y][x] == 'S' ||
				st->worldmap[y][x] == 'E' || st->worldmap[y][x] == 'W')
			{
				ft_configpos(st, st->worldmap[y][x]);
				st->posx = (double)x - 0.5;
				st->posy = (double)y - 0.5;
				player++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (player != 1)
		return (0);
	return (1);
}