/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:38:15 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:42:16 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	ft_get_ray_angle(int i)
{
	double	d;
	double	phi;

	d = (WIDTH / 2) - i - 0.5;
	phi = asin(d / (sqrt(pow(d, 2) + pow(WIDTH / 2, 2))));
	return (phi);
}

double	ft_get_angle(double agl)
{
	if (0 <= agl && agl <= (PI / 2))
		return (agl);
	else if ((PI / 2) < agl && agl <= PI)
		return (PI - agl);
	else if (PI < agl && agl <= (3 * PI / 2))
		return (agl - PI);
	else
		return ((2 * PI) - agl);
}

int	ft_round_ray(double round)
{
	float	tmp;

	tmp = round - (int)round;
	if (tmp < 0.5)
		return ((int)round);
	else
		return ((int)round + 1);
}

double	ft_generate_ray(t_game *g, double agl, double phi, char *c)
{
	t_ray	r;

	init_ray(&r, g, agl);
	first_ray_loop(&r, g);
	second_init_ray(&r, g);
	second_ray_loop(&r, g);
	return (determine_return(&r, g, phi, c));
}
