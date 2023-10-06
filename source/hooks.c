
#include "../include/cub3d.h"

void	ft_print_screen(t_game *g)
{
	int		j;
	int		i;
	double	t;

	i = -1;
	while (++i < 1024)
	{
		t = 300 / ft_generate_ray(g, g->angle + ft_get_ray_angle(i), ft_get_ray_angle(i));
		j = -1;
		while (++j < 1024)
		{
			if (j <= (HEIGHT / 2 - (t / 2)))
			{
				g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = 255;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = 255;	
			}
			else if (j > (HEIGHT / 2 - (t / 2)) && j < (HEIGHT / 2 + (t / 2)))
			{
				g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = 255;
			}
			else
			{
				g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = 255;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = 0;
				g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = 255;
			}
		}
	}
}
void	ft_hook(void *param)
{
	t_game			*g;

	g = (t_game *) param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		exit(-33);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
	{
		if (g->only_map[(int)(g->y_pos + g->y_delta * 0.1)][(int)(g->x_pos + g->x_delta * 0.1)] != '1')
		{
			g->y_pos += g->y_delta * 0.1;
			g->x_pos += g->x_delta * 0.1;
		}
		ft_print_screen(g);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		if (g->only_map[(int)(g->y_pos - g->y_delta * 0.1)][(int)(g->x_pos - g->x_delta * 0.1)] != '1')
		{
			g->y_pos -= g->y_delta * 0.1;
			g->x_pos -= g->x_delta * 0.1;
		}
		ft_print_screen(g);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_D))
	{
		if (g->only_map[(int)(g->y_pos + g->x_delta * 0.1)][(int)(g->x_pos - g->y_delta * 0.1)] != '1')	
		{
			g->x_pos -= g->y_delta * 0.1;
			g->y_pos += g->x_delta * 0.1;
		}
		ft_print_screen(g);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A))
	{
		if (g->only_map[(int)(g->y_pos - g->x_delta * 0.1)][(int)(g->x_pos + g->y_delta * 0.1)] != '1')
		{
			g->x_pos += g->y_delta * 0.1;
			g->y_pos -= g->x_delta * 0.1;
		}
		ft_print_screen(g);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
	{
		g->angle += 0.1;
		if (g->angle > 2 * PI)
			g->angle -= 2 * PI;
		g->x_delta = cos(g->angle);
		g->y_delta = -sin(g->angle);
		ft_print_screen(g);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
	{
		g->angle -= 0.1;
		if (g->angle <= 0)
			g->angle += 2 * PI;
		g->x_delta = cos(g->angle);
		g->y_delta = -sin(g->angle);
		ft_print_screen(g);
	}
}
