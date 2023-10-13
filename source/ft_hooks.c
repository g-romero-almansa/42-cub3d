
#include "../include/cub3d.h"

void	ft_print_screen(t_game *g)
{
	int		j;
	int		i;
	double	t;
	char	c;
	double	k;
	double	n;

	i = -1;
	c = 0;
	k = 0;
	while (++i < 1024)
	{
		t = 300 / ft_generate_ray(g, g->angle + ft_get_ray_angle(i), ft_get_ray_angle(i), &c);
		j = -1;
		while (++j < 1024)
		{
			k = (j - (HEIGHT / 2 - (t / 2))) / t * g->t_no->height;
			n = (g->t_location - (int)g->t_location) * g->t_no->width;
			if (j <= (HEIGHT / 2 - (t / 2)))
			{
				g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->c_color[0];
				g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->c_color[1];
				g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->c_color[2];
				g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = 255;	
			}
			else if (j > (HEIGHT / 2 - (t / 2)) && j < (HEIGHT / 2 + (t / 2)))
			{
				if (c == 'n')
				{
					g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->t_no->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 0];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->t_no->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 1];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->t_no->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 2];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = g->t_no->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 3];
				}
				else if (c == 's')
				{
					g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->t_so->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 0];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->t_so->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 1];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->t_so->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 2];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = g->t_so->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 3];
				}
				else if (c == 'e')
				{
					g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->t_ea->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 0];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->t_ea->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 1];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->t_ea->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 2];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = g->t_ea->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 3];
				}
				else if (c == 'w')
				{
					g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->t_we->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 0];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->t_we->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 1];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->t_we->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 2];
					g->img->pixels[WIDTH * j * 4 + i * 4 + 3] = g->t_we->pixels[g->t_no->width * (int)k * 4 + (int)n * 4 + 3];
				}
			}
			else
			{
				g->img->pixels[WIDTH * j * 4 + i * 4 + 0] = g->f_color[0];
				g->img->pixels[WIDTH * j * 4 + i * 4 + 1] = g->f_color[1];
				g->img->pixels[WIDTH * j * 4 + i * 4 + 2] = g->f_color[2];
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
