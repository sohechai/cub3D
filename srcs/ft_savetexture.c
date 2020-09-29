/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:47:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/29 16:03:44 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_saveNO(t_cubed *st)
{
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "NO", st) != NULL)
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
				st->path->texno = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_saveSO(t_cubed *st)
{
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "SO", st) != NULL)
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
				st->path->texso = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_saveEA(t_cubed *st)
{
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "EA", st) != NULL)
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
				st->path->texea = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_saveWE(t_cubed *st)
{
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "WE", st) != NULL)
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
				st->path->texwe = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_savetexture(t_cubed *st)
{
	if (ft_saveNO(st) == 0 || ft_saveSO(st) == 0||
		ft_saveEA(st) == 0 || ft_saveWE(st) == 0 || ft_savesprite(st) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("Wrong path file :\n\n");
		if (ft_saveNO(st) == 0)
			ft_errorpathNO(st);
		if (ft_saveSO(st) == 0)
			ft_errorpathSO(st);
		if (ft_saveEA(st) == 0)
			ft_errorpathEA(st);
		if (ft_saveWE(st) == 0)
			ft_errorpathWE(st);
		if (ft_savesprite(st) == 0)
			ft_errorpathsprite(st);
		// printf("textsprite = %s\n", st->path->texsprite);
		// printf("textno = %s\n", st->path->texno);
		// printf("textso = %s\n", st->path->texso);
		// printf("textea = %s\n", st->path->texea);
		// printf("textwe = %s\n", st->path->texwe);
		return (0);
	}
	else
		return (1);
}