/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:16:25 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strwrite(char const *s1, char const *s2, char *dest)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
	{
		dest[k] = s1[i++];
		k++;
	}
	if (i == ft_strlen(s1))
	{
		while (s2[j])
		{
			dest[k] = s2[j++];
			k++;
		}
	}
	dest[k] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	dest = ft_strwrite(s1, s2, dest);
	return (dest);
}
