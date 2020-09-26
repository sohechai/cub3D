/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaperror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:53:15 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/24 19:34:49 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int		ft_isnsew(int c)
// {
// 	if (c == 'N' )
// 		return (1);
// 	return (0);
// }

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
			if(x == 0 && st->worldmap[x][y] != '1' && st->worldmap[x][y] != ' ')
			{
				printf("c = [%c]\n", st->worldmap[x][y]);
				printf("erreur sur la 1ere ligne");
				return (0);
			}
			if(x == 0 && st->worldmap[x][y] == ' ')
			{
				if(st->worldmap[x + 1][y - 1] == '0' || st->worldmap[x + 1][y] == '0' ||
					st->worldmap[x + 1][y + 1] == '0')
				{
					printf("Error map pas fermée\n");
					return (0);
				}
			}
			if(y == 0 && st->worldmap[x][y] != '1' && st->worldmap[x][y] != ' ')
			{
				printf("erreur sur la 1ere colonne a gauche");
				return (0);
			}
			if(y == ft_strlen(st->worldmap[x]) &&
				st->worldmap[x][y] != '1' && st->worldmap[x][y] != ' ')
			{
				printf("erreur sur la derniere colonne a droite");
				return (0);
			}
			if(x == st->linenumber && st->worldmap[x][y] != '1' && st->worldmap[x][y] != ' ')
			{
				printf("erreur sur la derniere ligne");
				return (0);
			}
			y++;
		}
		y = 0;
    	x++;
	}
	return (1);
}