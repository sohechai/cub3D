/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:03:05 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/26 15:59:13 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// TODO verifier s'il faut gerer les cas de int max pour les res

void		ft_resizeres(t_cubed *st)
{
	if (st->width > 2560 || st->width < 0)
	{
		st->width = 2560;
		ft_putstr("Error, width have been resized at 2560\n");
	}
	else if (st->width < 150)
	{
		st->width = 150;
		ft_putstr("Error, width have been resized at 150\n");
	}
	if (st->height > 1520 || st->height < 0)
	{
		st->height = 1520;
		ft_putstr("Error, height have been resized at 1520\n");
	}
	else if (st->height < 150)
	{
		st->height = 150;
		ft_putstr("Error, height have been resized at 150\n");
	}
}

void		ft_saveres(t_cubed *st)
{
	int	error;

	error = 0;
	st->i = 0;
	while (st->mapfile[st->i] != '\0')
	{
		if(st->mapfile[st->i] == 'R')
		{
			st->i++;
			st->width = ft_atoiwithst(st->mapfile, st);
			if (st->mapfile[st->i] == ' ')
			{
				st->i++;
				st->height = ft_atoiwithst(st->mapfile, st);
			}
			else
			{
				error = 1;
				ft_putstr("Error, missing resolution on your map file");
			}
		}
		st->i++;
	}
	// printf("WIDTH = %d\n", st->width);
	// printf("HEIGHT = %d\n", st->height);
	if (error == 0)
		ft_resizeres(st);
}