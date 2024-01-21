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

int		ft_checkfiles(t_cubed *st)
{
	if (ft_checkdouble(st) == 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Do not duplicate informations in the file\n\n");
		ft_freesplits(st->checkdouble);
		return (0);
	}
	if (ft_saveres(st) == 0 || ft_savetexture(st) == 0 || ft_savecolor(st) == 0)
	{
		ft_freesplits(st->checkdouble);
		return (0);
	}
	if (ft_gotomap(st) == 0 || ft_maperror(st) == 0)
	{
		ft_freesplits(st->worldmap);
		ft_freesplits(st->checkdouble);
		free(st->finalmap);
		return (0);
	}
	st->map = ft_split(st->finalmap, '\n');
	free(st->finalmap);
	return (1);
}

int		ft_freesavefile(t_cubed *st)
{
	if (ft_checkfiles(st) == 0)
	{
		free(st->strcheck);
		free(st->tmp);
		free(st->mapfile);
		free(st->newstr);
		return (0);
	}
	ft_freesplits(st->worldmap);
	free(st->strcheck);
	free(st->tmp);
	free(st->mapfile);
	ft_freesplits(st->checkdouble);
	free(st->newstr);
	return (1);
}

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

void	ft_freesplits(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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
		ft_putstr("\e[41mError\e[00m\n- Map file was not found\n");
		return (0);
	}
	st->mapfile = ft_strdup(buf);
	st->tmp = ft_strdup(st->mapfile);
	st->strcheck = ft_strdup(st->tmp);
	st->checkdouble = ft_split(st->strcheck, '\n');
	close(fd);
	if (ft_freesavefile(st) == 0)
		return (0);
	return (1);
}
