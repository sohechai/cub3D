/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savecolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:57:53 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_checkcolor(t_cubed *st)
{
	if ((st->rgb->rgb.r > 0 && st->rgb->rgb.r < 255)
		&& (st->rgb->rgb.g > 0 && st->rgb->rgb.g < 255)
		&& (st->rgb->rgb.b > 0 && st->rgb->rgb.b < 255))
		return (1);
	return (0);
}

int			ft_savergbdata(t_cubed *st)
{
	if (st->mapfile[st->i] == ',')
	{
		st->i++;
		ft_jumpspaces(st);
		if (ft_isdigit(st->mapfile[st->i]) == 1)
			st->rgb->rgb.g = ft_atoiwithst(st->mapfile, st);
		else
			return (0);
		ft_jumpspaces(st);
		if (st->mapfile[st->i] == ',')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->rgb->rgb.b = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			ft_jumpspaces(st);
			if (st->mapfile[st->i] != '\n')
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

int			ft_save_ceilingcolor(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if (st->mapfile[st->i] == 'C')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->rgb->rgb.r = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			ft_jumpspaces(st);
			if (ft_savergbdata(st) == 0)
				return (0);
		}
		st->i++;
	}
	if (ft_checkcolor(st) == 1)
	{
		st->ceilingcol = st->rgb->rgb.r;
		st->ceilingcol = (st->ceilingcol << 8) + st->rgb->rgb.g;
		st->ceilingcol = (st->ceilingcol << 8) + st->rgb->rgb.b;
	}
	else
		return (0);
	return (1);
}

int			ft_save_floorcolor(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if (st->mapfile[st->i] == 'F')
		{
			st->i++;
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
				st->rgb->rgb.r = ft_atoiwithst(st->mapfile, st);
			else
				return (0);
			ft_jumpspaces(st);
			if (ft_savergbdata(st) == 0)
				return (0);
		}
		st->i++;
	}
	if (ft_checkcolor(st) == 1)
	{
		st->floorcol = st->rgb->rgb.r;
		st->floorcol = (st->floorcol << 8) + st->rgb->rgb.g;
		st->floorcol = (st->floorcol << 8) + st->rgb->rgb.b;
	}
	else
		return (0);
	return (1);
}

int			ft_savecolor(t_cubed *st)
{
	if (ft_save_ceilingcolor(st) == 0 || ft_save_floorcolor(st) == 0)
	{
		st->check = 1;
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
	return (1);
}
