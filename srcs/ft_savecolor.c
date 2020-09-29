/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savecolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:57:53 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/27 01:30:26 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_savergbdata(t_cubed *st)
{
	if (st->mapfile[st->i] == ',')
	{
		st->i++;
		ft_jumpspaces(st);
		if (ft_isdigit(st->mapfile[st->i]) == 1)
			st->colo->rgb.g = ft_atoiwithst(st->mapfile, st);
		else
			return (0);
		if (st->mapfile[st->i] == ',')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->colo->rgb.b = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			ft_jumpspaces(st);
			if (st->mapfile[st->i] != '\n')
				return (0);
			else
				return (1);
		}
	}
	return (0);
}

int			ft_save_ceilingcolor(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'C')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->colo->rgb.r = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			if (ft_savergbdata(st) == 0)
				return (0);
		}
		st->i++;
	}
	st->ceilingcol = st->colo->color;
}

int    ft_save_floorcolor(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'F')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->colo->rgb.r = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			if (ft_savergbdata(st) == 0)
				return (0);
		}
		st->i++;
	}
	st->floorcol = st->colo->color;
}

int		ft_savecolor(t_cubed *st)
{
	st->check = 0;
	if (ft_save_ceilingcolor(st) == 0 || ft_save_floorcolor(st) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Wrong rgb data on your map file:\n\n");
		if (ft_save_ceilingcolor(st) == 0)
			ft_error_rgbceiling(st);
		if (ft_save_floorcolor(st) == 0)
			ft_error_rgbfloor(st);
		return (0);
	}
	else
		return (1);
}