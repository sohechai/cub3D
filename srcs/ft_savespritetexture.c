/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savespritetexture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 00:25:41 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/29 00:26:08 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_savesprite(t_cubed *st)
{
	int	error;
	int	start;
	int	end;

	error = 0;
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "S ", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				end = st->i - start + 4;
				st->path->texsprite = ft_substr(st->mapfile, start, end);
				//printf("substr = [[%s]]\n", st->path->texno);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
}