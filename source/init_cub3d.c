#include "../include/cub3d.h"

void	ft_init_cub3d(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!g->mlx)
		exit(printf("\n[ERROR]: No se pudo crear MLX\n\n"));
	g->t_player = mlx_load_png("textures/barrel.png");
	g->player = mlx_texture_to_image(g->mlx, g->t_player);
	g->map = NULL;
	g->only_map = NULL;
	g->no = NULL;
	g->so = NULL;
	g->ea = NULL;
	g->we = NULL;
	g->f = NULL;
	g->c = NULL;
	g->x_player = 0;
	g->y_player = 0;
	g->r_limit = 0;
	g->c_limit = 0;
	g->x_pos = 0;
	g->y_pos = 0;
	g->x_delta = 0;
	g->y_delta = 0;
	g->angle = 0;
	g->img = mlx_new_image(g->mlx, 0x400, 0x400);
}
