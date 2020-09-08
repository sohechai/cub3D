# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char	*ft_searchdotcub(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - ft_strlen(".cub");
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

int     main()
{
    printf("%s\n", ft_searchdotcub("map.cub.txt", ".cub"));
}