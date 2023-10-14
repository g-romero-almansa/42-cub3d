/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:14 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:35:59 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_texture(t_game *g, t_draw *d, mlx_image_t *orientation)
{
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4
		+ 0] = orientation->pixels[orientation->width * (int)d->k * 4
		+ (int)d->n * 4 + 0];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4
		+ 1] = orientation->pixels[orientation->width * (int)d->k * 4
		+ (int)d->n * 4 + 1];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4
		+ 2] = orientation->pixels[orientation->width * (int)d->k * 4
		+ (int)d->n * 4 + 2];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4
		+ 3] = orientation->pixels[orientation->width * (int)d->k * 4
		+ (int)d->n * 4 + 3];
}

void	draw_sky(t_game *g, t_draw *d)
{
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 0] = g->c_color[0];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 1] = g->c_color[1];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 2] = g->c_color[2];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 3] = 255;
}

void	draw_floor(t_game *g, t_draw *d)
{
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 0] = g->f_color[0];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 1] = g->f_color[1];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 2] = g->f_color[2];
	g->img->pixels[WIDTH * d->j * 4 + d->i * 4 + 3] = 255;
}

void	draw_orientation(t_game *g, t_draw *d)
{
	if (d->c == 'n')
		draw_texture(g, d, g->t_no);
	else if (d->c == 's')
		draw_texture(g, d, g->t_so);
	else if (d->c == 'w')
		draw_texture(g, d, g->t_we);
	else if (d->c == 'e')
		draw_texture(g, d, g->t_ea);
}
