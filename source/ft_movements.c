/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:03:30 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:35:10 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_game *g)
{
	if (g->only_map[(int)(g->y_pos + g->y_delta * 0.1)][(int)(g->x_pos
			+ g->x_delta * 0.1)] != '1')
	{
		g->y_pos += g->y_delta * 0.1;
		g->x_pos += g->x_delta * 0.1;
	}
}

void	move_backward(t_game *g)
{
	if (g->only_map[(int)(g->y_pos - g->y_delta * 0.1)][(int)(g->x_pos
			- g->x_delta * 0.1)] != '1')
	{
		g->y_pos -= g->y_delta * 0.1;
		g->x_pos -= g->x_delta * 0.1;
	}
}

void	move_right(t_game *g)
{
	if (g->only_map[(int)(g->y_pos + g->x_delta * 0.1)][(int)(g->x_pos
			- g->y_delta * 0.1)] != '1')
	{
		g->x_pos -= g->y_delta * 0.1;
		g->y_pos += g->x_delta * 0.1;
	}
}

void	move_left(t_game *g)
{
	if (g->only_map[(int)(g->y_pos - g->x_delta * 0.1)][(int)(g->x_pos
			+ g->y_delta * 0.1)] != '1')
	{
		g->x_pos += g->y_delta * 0.1;
		g->y_pos -= g->x_delta * 0.1;
	}
}
