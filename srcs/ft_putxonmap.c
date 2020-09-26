/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxonmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:13:54 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/26 01:28:01 by sohechai         ###   ########lyon.fr   */
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
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
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

void	ft_putxonmap(t_cubed *st, char *str)
{
	printf("+ longue ligne = %d\n", ft_longestline(st, str));
	int		i;
	int		j;
	int		firstline = ft_longestline(st, str);
	int		scndline = ft_longestline(st, str);
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_strdup(str);
	while (str[j] && firstline > 0)
	{
		str[j] = 'X';
		j++;
		firstline--;
	}
	str[j] = '\n';
	j++;
	str[j] = 'X';
	j++;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			str[j] = 'X';
			j++;
			str[j] = '\n';
			j++;
			str[j] = 'X';
			j++;
			i++;
		}
		// if (tmp[i] == ' ')
		// {
		// 	str[j] = 'X';
		// 	j++;
		// 	i++;
		// }
		str[j] = tmp[i];
		i++;
		j++;
	}
	str[j] = 'X';
	j++;
	str[j] = '\n';
	j++;
	while (str[j] && scndline > 0)
	{
		str[j] = 'X';
		j++;
		scndline--;
	}
	str[j] = '\0';
	printf("str = [\n%s\n]", str);
}