

#include "../include/cub3d.h"

void	ft_print_minimap(t_game *g)
{
	int	i;
	int	j;
	int	ix = 0;
	int	jx = 0;
	int	k;
	int	l;
	g->delta = 35;

	i = -1;
	while (g->only_map[++i])
	{
		ix = i * (g->delta - 1);
		j = -1;
		while (g->only_map[i][++j])
		{
			jx = j * g->delta;
			k = -1;
			if (g->only_map[i][j] == '1' )
			{
				while (++k < g->delta)
				{
					l = -1;
					while (++l < g->delta)
						mlx_put_pixel(g->img, jx + l, ix + k, 0xFF14937F + l + k);
				}
			}
			else if (g->only_map[i][j] == '0' )
			{
				while (++k < g->delta)
				{
					l = -1;
					while (++l < g->delta)
						mlx_put_pixel(g->img, jx + l, ix + k, 0xFF8C007F + l + k);
				}
			}
			else
			{

				while (++k < g->delta)
				{
					l = -1;
					while (++l < g->delta)
						mlx_put_pixel(g->img, jx + l, ix + k, 0x9ACD327f + l + k);
					g->y_player = ix + k - g->delta / 2;
					g->x_player = jx + l - g->delta / 2;
				}
			}
		}
	}
}
