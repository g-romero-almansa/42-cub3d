/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:55:07 by gromero-          #+#    #+#             */
/*   Updated: 2023/10/14 14:14:48 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d.h"

void	ft_player_pov2(t_game *game, int i, int j)
{
	if (game->only_map[i][j] == 'N')
	{
		game->x_delta = 0;
		game->y_delta = -1;
		game->angle = PI / 2;
	}
	else if (game->only_map[i][j] == 'S')
	{
		game->x_delta = 0;
		game->y_delta = 1;
		game->angle = 3 * PI / 2;
	}
	else if (game->only_map[i][j] == 'W')
	{
		game->x_delta = -1;
		game->y_delta = 0;
		game->angle = PI;
	}
	else if (game->only_map[i][j] == 'E')
	{
		game->x_delta = 1;
		game->y_delta = 0;
		game->angle = 0;
	}
}

void	ft_player_pov(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->only_map[++i])
	{
		j = -1;
		while (game->only_map[i][++j])
		{
			if (game->only_map[i][j] == 'N' || game->only_map[i][j] == 'S'
				|| game->only_map[i][j] == 'W' || game->only_map[i][j] == 'E')
			{
				game->x_pos = j + 0.5;
				game->y_pos = i + 0.5;
			}
			ft_player_pov2(game, i, j);
		}
	}
	game->c_limit = j;
	game->r_limit = i;
}

void	ft_check_map2(t_game *game, int i, int j, int *check)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
		|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
	{
		(*check)++;
		game->x_player = j;
		game->y_player = i;
	}
	if (game->map[i][j] != 'N' && game->map[i][j] != 'S'
		&& game->map[i][j] != 'W' && game->map[i][j] != 'E'
		&& game->map[i][j] != '1' && game->map[i][j] != '0'
		&& game->map[i][j] != ' ' && game->map[i][j] != '\n'
		&& game->map[i][j] != '\t')
		ft_error(1);
}

void	ft_check_map(t_game *game, int start)
{
	int		check;
	int		i;
	int		j;

	check = 0;
	i = start;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_check_map2(game, i, j, &check);
	}
	if (check != 1 || game->map[game->y_player + 1][game->x_player] == ' '
		|| game->map[game->y_player + 1][game->x_player] == '\n'
		|| game->map[game->y_player - 1][game->x_player] == ' '
		|| game->map[game->y_player - 1][game->x_player] == '\n'
		|| game->map[game->y_player][game->x_player + 1] == ' '
		|| game->map[game->y_player][game->x_player + 1] == '\n'
		|| game->map[game->y_player][game->x_player - 1] == ' '
		|| game->map[game->y_player][game->x_player - 1] == '\n')
		ft_error(1);
}

void	ft_check_borders(t_game *g, int b)
{
	int		j;
	int		check;

	check = b + 1;
	while (g->map[++b])
	{
		j = -1;
		while (g->map[b][++j])
		{
			if (g->map[b][j] == '0'
				&& (b == check || !g->map[b + 1]))
				ft_error(1);
			if (g->map[b][j] == '0' && (g->map[b][j + 1] == ' '
				|| g->map[b][j + 1] == '\n' || g->map[b][j + 1] == '\t'
				|| g->map[b][j + 1] == '\0' || g->map[b][j - 1] == ' '
				|| g->map[b][j - 1] == '\n' || g->map[b][j - 1] == '\t'
				|| g->map[b][j - 1] == '\0' || g->map[b + 1][j] == ' '
				|| g->map[b + 1][j] == '\n' || g->map[b + 1][j] == '\t'
				|| g->map[b + 1][j] == '\0' || g->map[b - 1][j] == ' '
				|| g->map[b - 1][j] == '\n' || g->map[b - 1][j] == '\t'
				|| g->map[b - 1][j] == '\0'))
				ft_error(1);
		}
	}
}
