/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:10:13 by sohechai     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 16:32:25 by sohechai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count_words++;
		i++;
	}
	return (count_words);
}

static char		*ft_sizewords(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count_size;
	char	*tab_str;

	i = 0;
	j = 0;
	count_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count_size++;
		i++;
	}
	if (!(tab_str = malloc(sizeof(char) * count_size + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		tab_str[i] = s[i];
		i++;
	}
	tab_str[i] = '\0';
	return (tab_str);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;

	i = 0;
	if (!(tab = ft_calloc(sizeof(char*), (ft_countwords(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			if (!(tab[i] = ft_sizewords(s, c)))
			{
				free_tab(tab);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
