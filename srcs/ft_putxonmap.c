/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxonmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:13:54 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/26 21:11:11 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_longestline(t_cubed *st, char *str)
{
	int		count;
	int		longestline;
	int		i;

	count = 0;
	longestline = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == '\0')
		{
			if (count > longestline)
				longestline = count;
			count = 0;
		}
		count++;
		i++;
	}
	return (longestline + 1);
}

int		ft_numberofline(t_cubed *st, char *str)
{
	int		nbofline;
	int		i;

	nbofline = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nbofline++;
		i++;
	}
	return (nbofline);
}

// TODO raccourcir fonction
int	ft_putxonmap(t_cubed *st, char *str)
{
	int		i;
	int		j;
	int		longestline;
	int		lenuntiln;
	int		count;
	int		nbofline;
	char	*tmp;

	i = 0;
	j = 0;
	longestline = ft_longestline(st, str);
	lenuntiln = 0;
	count = longestline;
	nbofline = ft_numberofline(st, str);
	tmp = ft_strdup(str);
	if (!(st->newstr = malloc(sizeof(char) * ((longestline + 2) * (nbofline + 2)) + 1)))
		return (NULL);
	while (count >= 0)
	{
		st->newstr[j] = 'X';
		j++;
		count--;
	}
	st->newstr[j] = '\n';
	j++;
	st->newstr[j] = 'X';
	j++;
	count = longestline;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n' || st->newstr[j] == '\n')
		{
			while (lenuntiln < count)
			{
				st->newstr[j] = 'X';
				j++;
				lenuntiln++;
			}
			lenuntiln = 0;
			st->newstr[j] = '\n';
			j++;
			st->newstr[j] = 'X';
			j++;
			i++;
		}
		st->newstr[j] = tmp[i];
		i++;
		j++;
		lenuntiln++;
	}
	st->newstr[j] = 'X';
	j++;
	st->newstr[j] = '\n';
	j++;
	count = longestline;
	while (count >= 0)
	{
		st->newstr[j] = 'X';
		j++;
		count--;
	}
	st->newstr[j] = '\0';
	ft_strcpy(str, st->newstr);
}