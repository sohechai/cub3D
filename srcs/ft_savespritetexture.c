/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savespritetexture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 00:25:41 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/29 16:05:06 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_savesprite(t_cubed *st)
{
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "S ", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		st->start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				st->end = st->i - st->start + 4;
				st->i += 4;
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				st->path->texsprite = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
}