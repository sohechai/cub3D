/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:23:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_searchdotcub(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - ft_strlen(".cub");
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

int		ft_checkfiles(t_cubed *st)
{
	int		x;
	int		y;

	st->check = 0;
	x = 0;
	y = 0;
	ft_checkdouble(st);
	if (ft_checktabcase(st) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Do not duplicate informations in the file\n\n");
		return (0);
	}
	ft_saveres(st);
	ft_savetexture(st);
	ft_savecolor(st);
	if (ft_gotomap(st) == 0)
		return (0);
	if (ft_maperror(st) == 0)
		return (0);
	st->map = ft_split(st->finalmap, '\n');
	free(st->finalmap);
	return (1);
}

int		ft_savecub(t_cubed *st, char *filemap)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(filemap, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		buf[ret] = '\0';
	if (fd < 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Map file was not found\n\n");
		return (0);
	}
	st->mapfile = ft_strdup(buf);
	st->tmp = ft_strdup(st->mapfile);
	st->strcheck = ft_strdup(st->tmp);
	st->checkdouble = ft_split(st->strcheck, '\n');
	close(fd);
	ft_checkfiles(st);
	free(st->worldmap);
	free(st->strcheck);
	free(st->tmp);
	free(st->mapfile);
	free(st->checkdouble);
	return (1);
}
