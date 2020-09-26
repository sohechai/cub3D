/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:32:11 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/17 19:28:09 by sohechai         ###   ########lyon.fr   */
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
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
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
		return (NULL);
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
}