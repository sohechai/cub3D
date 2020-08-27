/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:40:21 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/27 21:18:47 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = ft_strlen(s);
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len != 0 && start < size)
	{
		dest[i] = s[start];
		start++;
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
