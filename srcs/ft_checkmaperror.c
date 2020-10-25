/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaperror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:53:15 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isposorobj(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '2')
		return (1);
	return (0);
}

int		ft_issurrouded(int c, t_cubed *st, int x, int y)
{
	if (st->worldmap[x][y - 1] == c || st->worldmap[x - 1][y - 1] == c ||
		st->worldmap[x - 1][y] == c || st->worldmap[x - 1][y + 1] == c ||
		st->worldmap[x][y + 1] == c || st->worldmap[x + 1][y + 1] == c ||
		st->worldmap[x + 1][y] == c || st->worldmap[x + 1][y - 1] == c)
		return (1);
	return (0);
}

int		ft_checkmaperror(t_cubed *st)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (st->worldmap[x] != 0)
	{
		while (st->worldmap[x][y] != '\0')
		{
			if (ft_isposorobj(st->worldmap[x][y]) == 1)
			{
				if (ft_issurrouded('X', st, x, y) == 1)
					return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int		ft_maperror(t_cubed *st)
{
	if (ft_checkmaperror(st) == 0)
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Map is open:\n\n");
		ft_putstr("-Map must be closed\n");
		return (0);
	}
	if (ft_checkmapcar(st) == 0)
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Forbidden map character :\n\n");
		ft_putstr("-Only 0, 1, 2, N, S, E and W are allowed\n");
		return (0);
	}
	if (ft_checkplayer(st) == 0)
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Map contain more than one player position:\n\n");
		ft_putstr("-Map must contain only one player position\n");
		return (0);
	}
	return (1);
}
