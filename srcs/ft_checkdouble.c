/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:32:11 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 21:17:36 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_checktabcase(t_cubed *st)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < st->sizetab)
	{
		while (j < st->sizetab)
		{
			if (st->tab[i] == st->tab[j] && i != j)
			{
				st->check = 1;
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(st->tab);
	return (1);
}

int		ft_checkdouble(t_cubed *st)
{
	int 	x;
	int		i;

	x = 0;
	i = 0;
	st->sizetab = 0;
	while (st->checkdouble[x] != 0)
	{
		if (ft_isalpha(st->checkdouble[x][0]) == 1)
			st->sizetab++;
		x++;
	}
	if (!(st->tab = malloc(sizeof(int) * st->sizetab)))
		return (0);
	x = 0;
	while (st->checkdouble[x] != 0)
	{
		if (ft_isalpha(st->checkdouble[x][0]) == 1)
		{
			st->tab[i] = st->checkdouble[x][0];
			if (ft_isalpha(st->checkdouble[x][1]) == 1)
				st->tab[i] += st->checkdouble[x][1];
			i++;
		}
		x++;
	}
	return (1);
}