/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:21:47 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	k;
	char	*sdest;
	char	*ssrc;

	i = 0;
	k = 0;
	sdest = (char*)dest;
	ssrc = (char*)src;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		sdest[k] = ssrc[i++];
		k++;
	}
	return (sdest);
}
