/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:33:12 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:33:51 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_print_screen(t_game *g)
{
	t_draw	d;

	d.i = -1;
	d.c = 0;
	d.k = 0;
	while (++d.i < WIDTH)
	{
		d.t = 300 / ft_generate_ray(g, g->angle + ft_get_ray_angle(d.i),
				ft_get_ray_angle(d.i), &d.c);
		d.j = -1;
		while (++d.j < HEIGHT)
		{
			d.k = (d.j - (HEIGHT / 2 - (d.t / 2))) / d.t * g->t_no->height;
			d.n = (g->t_location - (int)g->t_location) * g->t_no->width;
			if (d.j <= (HEIGHT / 2 - (d.t / 2)))
				draw_sky(g, &d);
			else if (d.j > (HEIGHT / 2 - (d.t / 2)) && d.j < (HEIGHT / 2 + (d.t
						/ 2)))
				draw_orientation(g, &d);
			else
				draw_floor(g, &d);
		}
	}
}

void	turn_left(t_game *g)
{
	g->angle += 0.1;
	if (g->angle > 2 * PI)
		g->angle -= 2 * PI;
	g->x_delta = cos(g->angle);
	g->y_delta = -sin(g->angle);
}

void	turn_right(t_game *g)
{
	g->angle -= 0.1;
	if (g->angle <= 0)
		g->angle += 2 * PI;
	g->x_delta = cos(g->angle);
	g->y_delta = -sin(g->angle);
}

void	ft_hook(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		exit(-33);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		move_forward(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		move_backward(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		move_left(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		move_right(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		turn_left(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		turn_right(g);
	ft_print_screen(g);
}
