/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:23:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/28 19:57:55 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
// TODO regler le pb de .cub pour pouvoir prendre n'importe lequel

int    ft_savecub(t_cubed *st)
{
	int     fd;
	int     ret;
	int     i;

	char    buf[BUF_SIZE + 1];
	i = 0;
	fd = open("map/map.cub", O_RDONLY);
	while((ret = read(fd, buf, BUF_SIZE)) > 0)
		buf[ret] = '\0';
	if (!(st->mapfile = malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (NULL);
	// TODO free mapfile
	ft_strcpy(st->mapfile, buf);
	// close(fd);
	ft_saveres(st);
	ft_savetexture(st);
	// ft_savecolor(st);
}