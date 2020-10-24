/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:03:05 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 21:15:56 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_resizeres(t_cubed *st, t_window *window)
{
	if (st->window->width > 1780 || st->window->width < 0)
	{
		st->window->width = 1780;
		ft_putstr("\e[7mNote:\e[00m\nWidth have been resized at 1080\n\n");
	}
	else if (st->window->width < 150)
	{
		st->window->width = 150;
		ft_putstr("\e[7mNote:\e[00m\nWidth have been resized at 150\n\n");
	}
	if (st->window->height > 1000 || st->window->height < 0)
	{
		st->window->height = 1000;
		ft_putstr("\e[7mNote:\e[00m\nHeight have been resized at 1024\n\n");
	}
	else if (st->window->height < 150)
	{
		st->window->height = 150;
		ft_putstr("\e[7mNote:\e[00m\nHeight have been resized at 150\n\n");
	}
}

int		ft_checkres(t_cubed *st, t_window *window)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'R')
		{
			st->i++;
			st->window->width = ft_atoiwithst(st->mapfile, st);
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
			{
				st->window->height = ft_atoiwithst(st->mapfile, st);
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				else
					return (1);
			}
			return (0);
		}
		st->i++;
	}
	return (0);
}

int		ft_saveres(t_cubed *st)
{
	if (ft_checkres(st, st->window) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Wrong rgb data on your map file:\n\n");
		ft_putstr("Please follow this exemple :\n");
		ft_putstr("1920 1080\n\n");
		st->check = 1;
		return (0);
	}
	else
	{
		ft_resizeres(st, st->window);
		return (1);
	}
	return (1);
}
