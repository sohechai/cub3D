/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:39 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	i;
	size_t	j;

	lendest = ft_strlen(dest);
	i = 0;
	j = 0;
	if (lendest > size)
		return (ft_strlen(src) + size);
	while (src[i] && size - lendest > 1)
	{
		dest[lendest + i] = src[j];
		i++;
		j++;
		size--;
	}
	dest[lendest + j] = '\0';
	return (ft_strlen(src) + lendest);
}
