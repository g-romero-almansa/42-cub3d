/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:31:19 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:38:12 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_ray *r, t_game *g, double agl)
{
	if (agl < 0)
		agl += 2 * PI;
	else if (agl >= 2 * PI)
		agl -= 2 * PI;
	r->x_ray = cos(agl);
	r->y_ray = -sin(agl);
	r->ap_angle = ft_get_angle(agl);
	if (r->y_ray > 0)
		r->y_dis = (int)g->y_pos + 1 - g->y_pos;
	else
		r->y_dis = g->y_pos - (int)g->y_pos;
	r->y_h = r->y_dis / sin(r->ap_angle);
	if (r->y_ray < 0)
		r->i = ft_round_ray(r->y_h * r->y_ray + g->y_pos) - 1;
	else
		r->i = ft_round_ray(r->y_h * r->y_ray + g->y_pos);
	r->j = r->y_h * r->x_ray + g->x_pos;
	g->t_location = (r->y_h * r->x_ray + g->x_pos);
}

void	first_ray_loop(t_ray *r, t_game *g)
{
	while (r->i > 0 && ft_round_ray(r->j) > 0 && r->i < g->r_limit
		&& ft_round_ray(r->j) < g->c_limit
		&& g->only_map[r->i][ft_round_ray(r->j)] != '1')
	{
		r->y_h += 1 / sin(r->ap_angle);
		if (r->y_ray < 0)
			r->i--;
		else
			r->i++;
		r->j = (r->y_h * r->x_ray + g->x_pos);
		g->t_location = (r->y_h * r->x_ray + g->x_pos);
	}
}

void	second_init_ray(t_ray *r, t_game *g)
{
	r->tpm = 0;
	if (r->x_ray > 0)
		r->x_dis = (int)g->x_pos + 1 - g->x_pos;
	else
		r->x_dis = g->x_pos - (int)g->x_pos;
	r->x_h = r->x_dis / cos(r->ap_angle);
	if (r->x_ray < 0)
		r->j = ft_round_ray(r->x_h * r->x_ray + g->x_pos) - 1;
	else
		r->j = ft_round_ray(r->x_h * r->x_ray + g->x_pos);
	r->i = r->x_h * r->y_ray + g->y_pos;
	r->tpm = (r->x_h * r->y_ray + g->y_pos);
}

void	second_ray_loop(t_ray *r, t_game *g)
{
	while (ft_round_ray(r->i) > 0 && r->j > 0 && ft_round_ray(r->i) < g->r_limit
		&& r->j < g->c_limit && g->only_map[ft_round_ray(r->i)][r->j] != '1')
	{
		r->x_h += 1 / cos(r->ap_angle);
		if (r->x_ray < 0)
			r->j--;
		else
			r->j++;
		r->i = (r->x_h * r->y_ray + g->y_pos);
		r->tpm = (r->x_h * r->y_ray + g->y_pos);
	}
}

double	determine_return(t_ray *r, t_game *g, double phi, char *c)
{
	if (r->x_h > r->y_h)
	{
		if (r->y_ray >= 0)
			*c = 'n';
		else
			*c = 's';
		return (r->y_h * cos(phi));
	}
	else
	{
		if (r->x_ray >= 0)
			*c = 'w';
		else
			*c = 'e';
		g->t_location = r->tpm;
		return (r->x_h * cos(phi));
	}
}
