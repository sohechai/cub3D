/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:03:27 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/24 18:59:58 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_cpy(char *dest, char const *s1, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[start] && start < len)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_checkstart(char const *s1, char const *set)
{
	size_t	count_start;
	size_t	i;

	count_start = 0;
	i = 0;
	while (set[i])
	{
		while (s1[count_start] == set[i])
		{
			count_start++;
			i = 0;
		}
		i++;
	}
	return (count_start);
}

static int		ft_checkend(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	count_end;

	len = ft_strlen(s1) - 1;
	i = 0;
	count_end = 0;
	while (set[i] != '\0')
	{
		while (s1[len] == set[i])
		{
			len--;
			i = 0;
			count_end++;
		}
		i++;
	}
	return (count_end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*dest;

	start = ft_checkstart(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_checkend(s1, set);
	len = ft_strlen(s1) - end;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) - start - end) + 1)))
		return (NULL);
	ft_cpy(dest, s1, start, len);
	return (dest);
	return (0);
}
