/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:23:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/08 21:15:43 by sohechai         ###   ########lyon.fr   */
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

int    ft_savecub(t_cubed *st, char *filemap)
{
	int     fd;
	int     ret;
	int     i;

	char    buf[BUF_SIZE + 1];
	i = 0;

	fd = open(filemap, O_RDONLY);
	while((ret = read(fd, buf, BUF_SIZE)) > 0)
		buf[ret] = '\0';
	if (fd < 0)
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Map file was not found\n\n");
		return (0);
	}
	// printf("S = |%s|\n", buf);
	if (!(st->mapfile = malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (NULL);
	// TODO free mapfile
	ft_strcpy(st->mapfile, buf);
	// close(fd);
	// ft_reserror(st); // OK
	// ft_savetexture(st); // OK
	// ft_savecolor(st); // OK
}