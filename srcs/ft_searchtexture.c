/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchtexture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:53:13 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_searchtextureeol(const char *s1, const char *s2, t_cubed *st)
{
	size_t	j;

	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[st->i] != '\n' && s1[st->i] != ' ')
	{
		while (s1[st->i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + st->i);
			j++;
		}
		st->i++;
		j = 0;
	}
	return (NULL);
}

char	*ft_searchtexture(const char *s1, const char *s2, t_cubed *st)
{
	size_t	j;

	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[st->i] != '\0')
	{
		while (s1[st->i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + st->i);
			j++;
		}
		st->i++;
		j = 0;
	}
	return (NULL);
}
