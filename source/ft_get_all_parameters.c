/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_parameters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:44 by gromero-          #+#    #+#             */
/*   Updated: 2023/10/14 13:52:34 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d.h"

void	ft_get_no_so(t_game *game, int i, int j, int *bigger)
{
	if (game->map[i][j] == 'N' && game->map[i][j + 1] == 'O')
	{
		if (!game->no)
			game->no = ft_strdup(game->map[i]);
		else
			ft_error(1);
		if (*bigger < i)
			*bigger = i;
	}
	else if (game->map[i][j] == 'S' && game->map[i][j + 1] == 'O')
	{
		if (!game->so)
			game->so = ft_strdup(game->map[i]);
		else
			ft_error(1);
		if (*bigger < i)
			*bigger = i;
	}
}

void	ft_get_we_ea(t_game *game, int i, int j, int *bigger)
{
	if (game->map[i][j] == 'W' && game->map[i][j + 1] == 'E')
	{
		if (!game->we)
			game->we = ft_strdup(game->map[i]);
		else
			ft_error(1);
		if (*bigger < i)
			*bigger = i;
	}
	else if (game->map[i][j] == 'E' && game->map[i][j + 1] == 'A')
	{
		if (!game->ea)
			game->ea = ft_strdup(game->map[i]);
		else
			ft_error(1);
		if (*bigger < i)
			*bigger = i;
	}
}

void	ft_get_c_f(t_game *game, int i, int j, int *bigger)
{
	if (game->map[i][j] == 'F')
	{
		if (!game->f)
		{
			game->f = ft_strdup(game->map[i]);
			ft_check_color(game->f, 'F');
			ft_get_fcolor(game, game->f);
		}
		else
			ft_error(1);
	}
	else if (game->map[i][j] == 'C')
	{
		if (!game->c)
		{
			game->c = ft_strdup(game->map[i]);
			ft_check_color(game->c, 'C');
			ft_get_ccolor(game, game->c);
		}
		else
			ft_error(1);
	}
	if (game->map[i][j] == 'F' || game->map[i][j] == 'C')
		if (*bigger < i)
			*bigger = i;
}
