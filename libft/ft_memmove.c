/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:44:16 by sohechai     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:14:41 by sohechai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;
	size_t			i;

	sdest = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	if (ssrc < sdest)
	{
		while (n--)
			sdest[n] = ssrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (sdest);
}
