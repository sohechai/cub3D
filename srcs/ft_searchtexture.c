/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchtexture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:53:13 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/28 23:08:03 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_searchtextureEOL(const char *s1, const char *s2, t_cubed *st)
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