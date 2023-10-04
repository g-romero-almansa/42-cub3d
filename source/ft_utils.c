
#include "../include/cub3d.h"

static char	**point_to_strings(char *memory, unsigned int len, int words)
{
	char			**array;
	unsigned int	i;
	unsigned int	w;

	array = (char **) malloc(sizeof(char *) * (words + 1));
	if (array == 0)
		return (0);
	i = 0;
	w = 0;
	if (memory[i] != '\0')
		array[w++] = ft_strdup(&memory[i]);
	i++;
	while (i < len)
	{
		if (memory[i] != '\0' && memory[i - 1] == '\0')
			array[w++] = ft_strdup(&memory[i]);
		i++;
	}
	array[w] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				words;
	char			*memory;
	char			**array;

	len = ft_strlen((char *)s);
	memory = ft_strdup((char *)s);
	if (!memory)
		return (0);
	words = 0;
	i = 0;
	while (i < len)
	{
		if (memory[i] == c)
			memory[i] = '\0';
		else if (i == 0 || memory[i - 1] == '\0')
			words++;
		i++;
	}
	array = point_to_strings(memory, len, words);
	free(memory);
	return (array);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	size_t	i;

	cpy = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}

void	ft_strcmp_ext(char *map, char *cmp)
{
	int		len;
	int		i;

	len = ft_strlen(map) - 1;
	while (map[len] == ' ' || map[len] == '\t')
		len--;
	len -= 4;
	i = -1;
	while (map[++len] && i < 3)
		if (map[len] != cmp[++i])
			ft_error(1);
}
