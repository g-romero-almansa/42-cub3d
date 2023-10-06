
#include "../include/cub3d.h"

void	ft_check_color(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i] != c)
		if (s[i] != ' ' && s[i] != '\t')
			ft_error(1);
	while (s[++i])
		if (s[i] != c && s[i] != ' ' && s[i] != '\t'
			&& (s[i] < '0' || s[i] > '9')
			&& s[i] != ',')
			ft_error(1);
}

void	ft_check_parameters(t_game *game)
{
	ft_strcmp_ext(game->no, ".png");
	ft_strcmp_ext(game->so, ".png");
	ft_strcmp_ext(game->ea, ".png");
	ft_strcmp_ext(game->we, ".png");
	ft_check_texture_format(game->no, "NO");
	ft_check_texture_format(game->so, "SO");
	ft_check_texture_format(game->ea, "EA");
	ft_check_texture_format(game->we, "WE");
}

void	ft_check_texture_format(char *s, char *f)
{
	int		i;

	i = -1;
	while (s[++i] != f[0])
		if (s[i] != ' ' && s[i] != '\t')
			ft_error(1);
	if (s[++i] != f[1])
		ft_error(1);
	i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	ft_check_texture(s + i);
}

void	ft_check_texture(char *rute)
{
	char	*cpy;
	int		fd;
	int		i;
	int		j;

	cpy = malloc (ft_strlen(rute) * sizeof(char));
	i = -1;
	j = -1;
	while (rute[++i] && rute[i] != ' ' && rute[i] != '\t')
		cpy[++j] = rute[i];
	cpy[++j] = '\0';
	fd = open(cpy, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	free (cpy);
	close(fd);
}
