/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:03:05 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/10 21:11:34 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// TODO verifier s'il faut gerer les cas de int max pour les res

void		ft_resizeres(t_cubed *st)
{
	if (st->width > 2560 || st->width < 0)
	{
		st->width = 2560;
		ft_putstr("\e[7mNote:\e[00m\nWidth have been resized at 2560\n\n");
	}
	else if (st->width < 150)
	{
		st->width = 150;
		ft_putstr("\e[7mNote:\e[00m\nWidth have been resized at 150\n\n");
	}
	if (st->height > 1520 || st->height < 0)
	{
		st->height = 1520;
		ft_putstr("\e[7mNote:\e[00m\nHeight have been resized at 1520\n\n");
	}
	else if (st->height < 150)
	{
		st->height = 150;
		ft_putstr("\e[7mNote:\e[00m\nHeight have been resized at 150\n\n");
	}
}

int		ft_checkres(t_cubed *st)
{
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'R')
		{
			st->i++;
			st->width = ft_atoiwithst(st->mapfile, st);
			ft_jumpspaces(st);
			if (ft_isdigit(st->mapfile[st->i]) == 1)
			{
				st->height = ft_atoiwithst(st->mapfile, st);
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
}

int		ft_saveres(t_cubed *st)
{
	if (ft_checkres(st) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Wrong rgb data on your map file:\n\n");
		ft_putstr("Please follow this exemple :\n");
		ft_putstr("1920 1080\n\n");
		return (0);
	}
	else
	{
		ft_resizeres(st);
		return (1);
	}
	// printf("WIDTH = %d\n", st->width);
	// printf("HEIGHT = %d\n", st->height);
}