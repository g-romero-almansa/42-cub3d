
#include "../include/cub3d.h"

double	ft_get_angle(double agl)
{
	if (0 <= agl  && agl <= (PI / 2))
		return (agl);
	else if ((PI / 2) < agl && agl <= PI)
		return (PI - agl);
	else if (PI < agl && agl <= (3 * PI / 2))
		return (agl - PI);
	else
		return ((2 * PI) - agl);
}

double	ft_ray_delta_x(t_game *g, double agl)
{
	if (g->y_delta <= 0 && g->x_delta > 0)
		return (cos(agl));
	else if (g->y_delta <= 0 && g->x_delta < 0)
		return (cos(agl));
	else if (g->y_delta >= 0 && g->x_delta < 0)
		return (cos(agl));
	else
		return (cos(agl));
}

double ft_ray_delta_y(t_game *g, double agl)
{
	if (g->y_delta <= 0 && g->x_delta >= 0)
		return (-sin(agl));
	else if (g->y_delta <= 0 && g->x_delta <= 0)
		return (-sin(agl));
	else if (g->y_delta >= 0 && g->x_delta <= 0)
		return (-sin(agl));
	else
		return (-sin(agl));
}

int		ft_round_ray(double round)
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
	double	y_dis;
	double	y_h;
	double	ap_angle;
	int		i;
	int		j;
	double	x_ray;
	double	y_ray;

	if (agl < 0)
		agl += 2 * PI;
	else if (agl >= 2 * PI)
		agl -= 2 * PI;
	x_ray = ft_ray_delta_x(g, agl);
	y_ray = ft_ray_delta_y(g, agl);
	ap_angle = ft_get_angle(agl);
	if (y_ray > 0)
		y_dis = (int)g->y_pos + 1 - g->y_pos;
	else
		y_dis = g->y_pos - (int)g->y_pos;
	y_h = y_dis / sin(ap_angle);
	if (y_ray < 0)
		i = ft_round_ray(y_h * y_ray + g->y_pos) - 1;
	else
		i = ft_round_ray(y_h * y_ray + g->y_pos);
	j = y_h * x_ray + g->x_pos;
	g->t_location = (y_h * x_ray + g->x_pos);
	while (i > 0 && ft_round_ray(j) > 0 && i < g->r_limit && ft_round_ray(j) < g->c_limit
			&& g->only_map[i][ft_round_ray(j)] != '1')
	{
		y_h += 1 / sin(ap_angle);
		if (y_ray < 0)
			i--;
		else
			i++;
		j = (y_h * x_ray + g->x_pos);
		g->t_location = (y_h * x_ray + g->x_pos);
	}

	double	x_dis;
	double	x_h;
	double	tpm;

	tpm = 0;
	if (x_ray > 0)
		x_dis = (int)g->x_pos + 1 - g->x_pos;
	else
		x_dis = g->x_pos - (int)g->x_pos;
	x_h = x_dis / cos(ap_angle);
	if (x_ray < 0)
		j = ft_round_ray(x_h * x_ray + g->x_pos) - 1;
	else
		j = ft_round_ray(x_h * x_ray + g->x_pos);
	i = x_h * y_ray + g->y_pos;
	tpm = (x_h * y_ray + g->y_pos);
	while (ft_round_ray(i) > 0 && j > 0 && ft_round_ray(i) < g->r_limit && j < g->c_limit
			&& g->only_map[ft_round_ray(i)][j] != '1')
	{
		x_h += 1 / cos(ap_angle);
		if (x_ray < 0)
			j--;
		else
			j++;
		i = (x_h * y_ray + g->y_pos);
		tpm = (x_h * y_ray + g->y_pos);
	}
	if (x_h > y_h)
	{
		if (g->y_delta >= 0)
			*c = 'n';
		else
			*c = 's';
		//g->t_location = tpm;
		return (y_h * cos(phi));
	}
	else
	{
		if (g->x_delta > 0)
			*c = 'w';
		else
			*c = 'e';
		g->t_location = tpm;
		return (x_h * cos(phi));
	}
}
