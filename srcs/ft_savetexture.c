/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:47:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_saveno(t_cubed *st, t_img *texture)
{
	st->i = 0;
	if (ft_searchtexture(st->mapfile, "NO", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		st->start = st->i;
		if (st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureeol(st->mapfile, ".xpm", st) != NULL)
			{
				st->end = st->i - st->start + 4;
				st->i += 4;
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				texture->path = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_saveso(t_cubed *st, t_img *texture)
{
	st->i = 0;
	if (ft_searchtexture(st->mapfile, "SO", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		st->start = st->i;
		if (st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureeol(st->mapfile, ".xpm", st) != NULL)
			{
				st->end = st->i - st->start + 4;
				st->i += 4;
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				texture->path = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_saveea(t_cubed *st, t_img *texture)
{
	st->i = 0;
	if (ft_searchtexture(st->mapfile, "EA", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		st->start = st->i;
		if (st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureeol(st->mapfile, ".xpm", st) != NULL)
			{
				st->end = st->i - st->start + 4;
				st->i += 4;
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				texture->path = ft_substr(st->mapfile, st->start, st->end);
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_savewe(t_cubed *st, t_img *texture)
{
	st->i = 0;
	if (ft_searchtexture(st->mapfile, "WE", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		st->start = st->i;
		if (st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureeol(st->mapfile, ".xpm", st) != NULL)
			{
				st->end = st->i - st->start + 4;
				st->i += 4;
				ft_jumpspaces(st);
				if (st->mapfile[st->i] != '\n')
					return (0);
				texture->path = ft_substr(st->mapfile, st->start, st->end);
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
	if (ft_saveno(st, st->north) == 0)
	{
		ft_errorpathso(st);
		return (0);
	}
	if (ft_saveso(st, st->south) == 0)
	{
		ft_errorpathso(st);
		return (0);
	}
	if (ft_saveea(st, st->east) == 0)
	{
		ft_errorpathso(st);
		return (0);
	}
	if (ft_savewe(st, st->west) == 0)
	{
		ft_errorpathso(st);
		return (0);
	}
	if (ft_savesprite(st, st->sprit) == 0)
	{
		ft_errorpathso(st);
		return (0);
	}
}
