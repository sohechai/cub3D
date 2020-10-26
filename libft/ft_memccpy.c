/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:34:58 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	sdest = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	if (src == NULL && dest == NULL)
		return (0);
	while (n != 0)
	{
		*sdest = *ssrc;
		if (*ssrc == (unsigned char)c)
			return (sdest + 1);
		sdest++;
		ssrc++;
		n--;
	}
	return (NULL);
}
