/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:47:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/27 23:15:57 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_saveNO(t_cubed *st)
{
	int	error;
	int	j;
	char	*map;

	error = 0;
	st->i = 0;
	j = 0;
	map = st->mapfile;
	if(ft_searchtexture(st->mapfile, "NO", st) != NULL)
	{
		st->i += 2;
		ft_jumpspaces(st);
		if (ft_searchtexture(st->mapfile, "./", st) != NULL)
		{
			st->i += 2;
			while (ft_isalpha(st->mapfile[st->i]) == 1)
				st->i++;
			st->i++;
			while (ft_isalpha(st->mapfile[st->i]) == 1)
			{
				st->i++;
				j++;
			}
			st->i -= j;
			//st->path->texno = ft_substr(st->mapfile, st->i, j);
			printf("i = %d ET j = %d\n", st->i, j);
		}
		// else
		// 	error = 1;
	}
	// else
	// {
	// 	error = 1;
	// 	printf("on est aussi dans le else\n");
	// }
	// if (error = 1)
	// 	ft_putstr("Error, missing path to texture for north");
}

void		ft_saveSO(t_cubed *st)
{
	int		error;

	error = 0;
	st->i = 0;
	if(ft_strstr(st->mapfile, "SO") != NULL)
	{
		ft_putstr("SO est la");
	}
	else
		error = 1;
	if (error == 1)
		ft_putstr("Error, missing path to texture for south");
}

void		ft_saveEA(t_cubed *st)
{
	int	error;

	error = 0;
	st->i = 0;
	if(ft_strstr(st->mapfile, "EA") != NULL)
	{
		ft_putstr("EA est la");
	}
	else
		error = 1;
	if (error == 1)
		ft_putstr("Error, missing path to texture for east");
}

void		ft_saveWE(t_cubed *st)
{
	int	error;

	error = 0;
	st->i = 0;
	if(ft_strstr(st->mapfile, "WE") != NULL)
	{
		ft_putstr("WE est la");
	}
	else
		error = 1;
	if (error == 1)
		ft_putstr("Error, missing path to texture for west");
}

void		ft_savetexture(t_cubed *st)
{
	int		error;

	error = 0;
	//st->i = 0;
	ft_saveNO(st);
	// ft_saveSO(st, spath);
	// ft_saveEA(st, spath);
	// ft_saveWE(st, spath);
}