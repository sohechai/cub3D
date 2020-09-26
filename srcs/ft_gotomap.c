/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotomap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:46:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/26 00:24:29 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_isntmap(t_cubed *st)
{
	if (st->tmp[st->i] == 'R' ||
		(st->tmp[st->i] == 'E' && st->tmp[st->i + 1] == 'A') ||
		(st->tmp[st->i] == 'N' && st->tmp[st->i + 1] == 'O') ||
		(st->tmp[st->i] == 'W' && st->tmp[st->i + 1] == 'E') ||
		(st->tmp[st->i] == 'S' && st->tmp[st->i + 1] == 'O') ||
		st->tmp[st->i] == 'S' || st->tmp[st->i] == 'C' ||
		st->tmp[st->i] == 'F')
		return (1);
	return (0);
}

void		ft_lineuntiln(char *str, t_cubed *st)
{
	while (str[st->i] != '\n')
	{
		st->count++;
		st->i++;
	}
}

void	ft_delete_n_spaces(t_cubed *st, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = '\0';
	j = 0;
	// printf("%s\n", str);
}

//TODO raccourcir cette fonction
//TODO faire la fonction qui check les erreurs de map

int		ft_gotomap(t_cubed *st)
{
	int		i;
	int		x = 0;
	int		y = 0;
	char	*str;

	st->i = 0;
	i = 0;
	str = st->tmp;
	while (st->tmp[st->i] != '\0')
	{
		if (ft_isntmap(st) == 1)
			ft_lineuntiln(st->tmp, st);
		str[i++] = st->tmp[st->i];
		st->i++;
	}
	str[i] = '\0';
	// i = 0;
	ft_delete_n_spaces(st, str);
	ft_putxonmap(st, str);
	st->worldmap = ft_split(str, '\n');
	while (st->worldmap[x] != 0)
	{
		while (st->worldmap[x][y] != '\0')
		{
		//printf("[%c]", st->worldmap[x][y]);
			y++;
		}
		y = 0;
		// printf("\n");
    	x++;
	}
	st->linenumber = x;
	if (str[0] == '\0')
	{
		ft_putstr("\e[41mError\e[00m\n\n- Missing map on your map file\n\n");
		return (0);
	}
	else
		return (1);
}