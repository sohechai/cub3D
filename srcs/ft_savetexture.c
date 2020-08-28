/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:47:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/29 00:31:56 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_saveNO(t_cubed *st)
{
	int	error;
	int	start;
	int	end;

	error = 0;
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "NO", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				end = st->i - start + 4;
				st->path->texno = ft_substr(st->mapfile, start, end);
				//printf("substr = [[%s]]\n", st->path->texno);
				return (1);
			}
			else
			{
				st->path->texno = ft_strdup("");
				return (0);
			}
		}
		return (0);
	}
}

int		ft_saveSO(t_cubed *st)
{
	int	error;
	int	start;
	int	end;

	error = 0;
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "SO", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				end = st->i - start + 4;
				st->path->texso = ft_substr(st->mapfile, start, end);
				//printf("substr = [[%s]]\n", st->path->texso);
				return (1);
			}
			else
			{
				st->path->texso = ft_strdup("");
				return (0);
			}
		}
		return (0);
	}
}

int		ft_saveEA(t_cubed *st)
{
	int	error;
	int	start;
	int	end;

	error = 0;
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "EA", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				end = st->i - start + 4;
				st->path->texea = ft_substr(st->mapfile, start, end);
				//printf("substr = [[%s]]\n", st->path->texea);
				return (1);
			}
			else
			{
				st->path->texea = ft_strdup("");
				return (0);
			}
		}
		return (0);
	}
}

int		ft_saveWE(t_cubed *st)
{
	int	error;
	int	start;
	int	end;

	error = 0;
	st->i = 0;
	if(ft_searchtexture(st->mapfile, "WE", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		start = st->i;
		if(st->mapfile[st->i] == '.' && st->mapfile[st->i + 1] == '/')
		{
			if (ft_searchtextureEOL(st->mapfile, ".xpm", st) != NULL)
			{
				end = st->i - start + 4;
				st->path->texwe = ft_substr(st->mapfile, start, end);
				//printf("substr = [[%s]]\n", st->path->texwe);
				return (1);
			}
			else
			{
				st->path->texwe = ft_strdup("");
				return (0);
			}
		}
		return (0);
	}
}

void		ft_savetexture(t_cubed *st)
{
	if (ft_saveNO(st) == 0 || ft_saveSO(st) == 0||
		ft_saveEA(st) == 0 || ft_saveWE(st) == 0 || ft_savesprite(st) == 0)
	{
		ft_putstr("Error\n");
		ft_putstr("Missing path file :\n\n");
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
	}
	printf("textsprite = %s\n", st->path->texsprite);
	printf("textno = %s\n", st->path->texno);
	printf("textso = %s\n", st->path->texso);
	printf("textea = %s\n", st->path->texea);
	printf("textwe = %s\n", st->path->texwe);
}