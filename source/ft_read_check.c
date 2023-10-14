/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:55:15 by gromero-          #+#    #+#             */
/*   Updated: 2023/10/14 13:52:59 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d.h"

void	ft_read_map(char *map, t_game *game)
{
	char	*big_str;
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	big_str = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		tmp = ft_strjoin(big_str, str);
		big_str = tmp;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	ft_check_newline(big_str, game);
	game->map = ft_split(big_str, '\n');
	free(big_str);
}

void	ft_check_newline(char *s, t_game *game)
{
	int		len;
	int		end;

	len = ft_strlen(s) - 1;
	while (s[len] && s[len] != 'C' && s[len] != 'F'
		&& (s[len] != 'E' || s[len - 1] != 'W')
		&& s[len] != 'A' && s[len] != 'O')
		len--;
	while (s[len] != '\n')
		len++;
	while (s[len] != '1')
		len++;
	game->only_map = ft_split(&s[len], '\n');
	end = ft_strlen(s) - 1;
	while (s[end] != '1')
		end--;
	while (s[len] && len < end)
	{
		if (s[len] == '\n' && s[len + 1] == '\n')
			ft_error(1);
		len++;
	}
}

void	ft_get_fcolor(t_game *g, char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->f_color[0] = res;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->f_color[1] = res;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->f_color[2] = res;
}

void	ft_get_ccolor(t_game *g, char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->c_color[0] = res;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->c_color[1] = res;
	res = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	g->c_color[2] = res;
}

void	ft_get_parameters(t_game *game)
{
	int		i;
	int		j;
	int		bigger;

	i = -1;
	bigger = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			ft_get_no_so(game, i, j, &bigger);
			ft_get_we_ea(game, i, j, &bigger);
			ft_get_c_f(game, i, j, &bigger);
		}
	}
	if (!game->no || !game->so || !game->we || !game->ea
		|| !game->f || !game->c)
		ft_error(1);
	ft_check_parameters(game);
	ft_check_map(game, bigger);
	ft_check_borders(game, bigger);
}
