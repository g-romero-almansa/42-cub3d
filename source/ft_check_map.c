/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:54:54 by gromero-          #+#    #+#             */
/*   Updated: 2023/10/14 12:19:36 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	ft_check_texture_format(game->no, "NO", game, 1);
	ft_check_texture_format(game->so, "SO", game, 2);
	ft_check_texture_format(game->ea, "EA", game, 3);
	ft_check_texture_format(game->we, "WE", game, 4);
}

void	ft_check_texture_format(char *s, char *f, t_game *g, int x)
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
	ft_check_texture((s + i), g, x);
}

void	ft_check_texture(char *rute, t_game *g, int x)
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
	if (x == 1)
	{
		free (g->no);
		g->no = cpy;
	}
	else if (x == 2)
	{
		free (g->so);
		g->so = cpy;
	}
	else if (x == 3)
	{
		free (g->ea);
		g->ea = cpy;
	}
	else if (x == 4)
	{
		free (g->we);
		g->we = cpy;
	}
	close(fd);
}
