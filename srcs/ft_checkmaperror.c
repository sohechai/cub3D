/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaperror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:53:15 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/26 21:19:52 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isposorobj(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '2')
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
			if(ft_isposorobj(st->worldmap[x][y]) == 1)
			{
				printf("c = [%c]\n", st->worldmap[x][y]);
			}
			y++;
		}
		y = 0;
    	x++;
	}
	return (1);
}