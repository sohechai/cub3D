/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 12:54:56 by sohechai     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 17:32:43 by sohechai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && len > 0)
	{
		k = len;
		while (s1[i + j] == s2[j] && k > 0)
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + i);
			j++;
			k--;
		}
		i++;
		j = 0;
		len--;
	}
	return (NULL);
}
