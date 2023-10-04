
#include "../include/cub3d.h"

void	ft_error(int e)
{
	if (e == 0)
		printf ("ERROR!, Wrong number of arguments!\n");
	else if (e == 1)
		printf ("ERROR!, Wrong type of map!\n");
	else if (e == 2)
		printf ("ERROR!, Can't open the map\n");
	exit (EXIT_FAILURE);
}

void	ft_free(t_game *game)
{
	int		i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	i = -1;
	while (game->only_map[++i])
		free(game->only_map[i]);
	free(game->no);
	free(game->so);
	free(game->we);
	free(game->ea);
	free(game->f);
	free(game->c);
	free(game->map);
	free(game->only_map);
	free(game);
}

double	ft_get_ray_angle(int i)
{
	double	d;
	double	phi;

	d = (WIDTH / 2) - i - 0.5;
	phi = asin(d / (sqrt(pow(d, 2) + pow(WIDTH / 2, 2))));
	return (phi);
}

void	ft_leaks()
{
	system("leaks -q cub3d");
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	t_game	g;

	//(void)argv;
	if (argc != 2)
		ft_error(0);
	ft_init_cub3d(&g);
	ft_strcmp_ext(argv[1], ".cub");
	ft_read_map(argv[1], &g);
	ft_get_parameters(&g);
	ft_player_pov(&g);
	mlx_image_to_window(g.mlx, g.img, 0, 0);
	ft_print_screen(&g);
	mlx_loop_hook(g.mlx, ft_hook, &g);
	mlx_loop(g.mlx);
	ft_free(&g);
	//exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
