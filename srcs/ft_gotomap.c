/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotomap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:46:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/29 17:48:28 by sohechai         ###   ########lyon.fr   */
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
		(st->tmp[st->i] == 'S' && st->tmp[st->i + 1] == ' ') ||
		st->tmp[st->i] == 'C' || st->tmp[st->i] == 'F')
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
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = '\0';
	j = 0;
}

int		ft_msgnomapfound(t_cubed *st, char *str)
{
	if (str[0] == '\0')
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Missing map on your map file\n\n");
		return (0);
	}
}

int		ft_gotomap(t_cubed *st)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	st->i = 0;
	i = 0;
	x = 0;
	y = 0;
	str = st->tmp;
	while (st->tmp[st->i] != '\0')
	{
		if (ft_isntmap(st) == 1)
			ft_lineuntiln(st->tmp, st);
		str[i++] = st->tmp[st->i];
		st->i++;
	}
	str[i] = '\0';
	ft_delete_n_spaces(st, str);
	ft_msgnomapfound(st, str);
	// TODO free v
	st->finalmap = ft_strdup(str);
	// printf("final map = %s\n", st->finalmap);
	ft_putxonmap(st, str);
	st->worldmap = ft_split(str, '\n');
	//
	// printf("str= %s\n", str);
	// while (st->worldmap[x] != 0)
	// {
	// 	while (st->worldmap[x][y] != '\0')
	// 	{
	// 		printf("[%c]", st->worldmap[x][y]);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	printf("\n");
    // 	x++;
	// }
	//
	return (1);
}