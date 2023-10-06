
#include "../include/cub3d.h"

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
	}
	game->c_limit = j;
	game->r_limit = i;
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
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				check++;
				//ft_player_pov(game, game->map[i][j], j, i);
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

void	ft_check_borders(t_game *game, int bigger)
{
	int		j;
	int		check;

	check = bigger + 1;
	while (game->map[++bigger])
	{
		j = -1;
		while (game->map[bigger][++j])
		{
			if (game->map[bigger][j] == '0' && (bigger == check || !game->map[bigger + 1]))
				ft_error(1);
			if (game->map[bigger][j] == '0' && (game->map[bigger][j + 1] == ' '
				|| game->map[bigger][j + 1] == '\n' || game->map[bigger][j + 1] == '\t'
				|| game->map[bigger][j + 1] == '\0' || game->map[bigger][j - 1] == ' '
				|| game->map[bigger][j - 1] == '\n' || game->map[bigger][j - 1] == '\t'
				|| game->map[bigger][j - 1] == '\0' || game->map[bigger + 1][j] == ' '
				|| game->map[bigger + 1][j] == '\n' || game->map[bigger + 1][j] == '\t'
				|| game->map[bigger + 1][j] == '\0' || game->map[bigger - 1][j] == ' '
				|| game->map[bigger - 1][j] == '\n' || game->map[bigger - 1][j] == '\t'
				|| game->map[bigger - 1][j] == '\0'))
				ft_error(1);
		}
	}
}
