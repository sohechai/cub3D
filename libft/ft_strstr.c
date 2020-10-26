/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:51:26 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/26 20:53:35 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
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
