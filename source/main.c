/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:54:06 by gromero-          #+#    #+#             */
/*   Updated: 2023/10/14 12:34:04 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	mlx_delete_texture(game->texture);
	mlx_delete_image(game->mlx, game->t_no);
	mlx_delete_image(game->mlx, game->t_so);
	mlx_delete_image(game->mlx, game->t_ea);
	mlx_delete_image(game->mlx, game->t_we);
	free(game->no);
	free(game->so);
	free(game->we);
	free(game->ea);
	free(game->f);
	free(game->c);
	free(game->f_color);
	free(game->c_color);
	free(game->map);
	free(game->only_map);
	//free(game);
}

void	ft_init_cub3d(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!g->mlx)
		exit(printf("\n[ERROR]: No se pudo crear MLX\n\n"));
	g->map = NULL;
	g->only_map = NULL;
	g->no = NULL;
	g->so = NULL;
	g->ea = NULL;
	g->we = NULL;
	g->x_player = 0;
	g->y_player = 0;
	g->r_limit = 0;
	g->c_limit = 0;
	g->x_pos = 0;
	g->y_pos = 0;
	g->x_delta = 0;
	g->y_delta = 0;
	g->angle = 0;	
	g->t_location = 0;
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->f_color = malloc(3 * sizeof(int));
	g->c_color = malloc(3 * sizeof(int));
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

void	ft_init_textures(t_game *g)
{
	g->texture = mlx_load_png(g->no);
	if (g->texture == NULL)
		ft_error(1);
	g->t_no = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png(g->so);
	if (g->texture == NULL)
		ft_error(1);
	g->t_so = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png(g->ea);
	if (g->texture == NULL)
		ft_error(1);
	g->t_ea = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png(g->we);
	if (g->texture == NULL)
		ft_error(1);
	g->t_we = mlx_texture_to_image(g->mlx, g->texture);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_game	g;

	if (argc != 2)
		ft_error(0);
	ft_init_cub3d(&g);
	ft_strcmp_ext(argv[1], ".cub");
	ft_read_map(argv[1], &g);
	ft_get_parameters(&g);
	ft_player_pov(&g);
	mlx_image_to_window(g.mlx, g.img, 0, 0);
	ft_init_textures(&g);
	ft_print_screen(&g);
	mlx_loop_hook(g.mlx, ft_hook, &g);
	mlx_loop(g.mlx);
	ft_free(&g);
	//exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
