/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxonmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:13:54 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"

int			ft_longestline(t_cubed *st, char *str)
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

int			ft_numberofline(t_cubed *st, char *str)
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

void		ft_putlineofx(t_cubed *st)
{
	st->lenmax = st->longestline;
	while (st->lenmax >= 0)
	{
		st->newstr[st->l] = 'X';
		st->l++;
		st->lenmax--;
	}
}

void		ft_replacespacex(t_cubed *st, char *tmp)
{
	while (tmp[st->k] != '\0')
	{
		if (tmp[st->k] == '\n')
		{
			while (st->lenuntiln < st->lenmax)
			{
				st->newstr[st->l] = 'X';
				st->l++;
				st->lenuntiln++;
			}
			st->lenuntiln = 0;
			st->newstr[st->l] = '\n';
			st->l++;
			st->newstr[st->l] = 'X';
			st->l++;
			st->k++;
		}
		if (tmp[st->k] == ' ')
			st->newstr[st->l] = 'X';
		else
			st->newstr[st->l] = tmp[st->k];
		st->k++;
		st->l++;
		st->lenuntiln++;
	}
}

int			ft_putxonmap(t_cubed *st, char *str)
{
	st->longestline = ft_longestline(st, str);
	st->nbofline = ft_numberofline(st, str);
	st->lenuntiln = 0;
	st->lenmax = st->longestline;
	st->tmp2 = ft_strdup(str);
	if (!(st->newstr = malloc(sizeof(char) *
		((st->longestline + 2) * (st->nbofline + 2)) + 1)))
		return (0);
	ft_putlineofx(st);
	st->newstr[st->l] = '\n';
	st->l++;
	st->newstr[st->l] = 'X';
	st->l++;
	st->lenmax = st->longestline;
	ft_replacespacex(st, st->tmp2);
	st->newstr[st->l] = 'X';
	st->l++;
	st->newstr[st->l] = '\n';
	st->l++;
	ft_putlineofx(st);
	st->newstr[st->l] = '\0';
	ft_strcpy(str, st->newstr);
	free(st->tmp2);
	return (1);
}
