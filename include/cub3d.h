
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define PI		M_PI
# define WIDTH	1024
# define HEIGHT	1024

typedef struct s_game
{
	double			delta;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	mlx_image_t		*t_no;
	mlx_image_t		*t_so;
	mlx_image_t		*t_ea;
	mlx_image_t		*t_we;
	char	**map;
	char	**only_map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	int		*f_color;
	int		*c_color;
	int		x_player;
	int		y_player;
	double	r_limit;
	double	c_limit;
	double	x_pos;
	double	y_pos;
	double	x_delta;
	double	y_delta;
	double	angle;;
	double	t_location;
}	t_game;

/*MAIN.C*/
void	ft_free(t_game *game);
void	ft_error(int e);
double	ft_get_ray_angle(int i);

/*FT_UTILS.C*/
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
void	ft_strcmp_ext(char *map, char *cmp);

/*FT_READ_CHECK.C*/
void	ft_read_map(char *map, t_game *game);
void	ft_check_newline(char *s, t_game *game);
void	ft_get_parameters(t_game *game);

/*FT_CHECK_MAP.C*/
void	ft_check_color(char *s, char c);
void	ft_check_parameters(t_game *game);
void	ft_check_texture_format(char *s, char *f, t_game *g, int x);
void	ft_check_texture(char *rute, t_game *g, int x);

/*FT_CHECK_MAP_FORMAT.C*/
void	ft_player_pov(t_game *game);
void	ft_check_map(t_game *game, int start);
void	ft_check_borders(t_game *game, int bigger);

//hooks
void	ft_hook(void *param);
void	ft_print_screen(t_game *g);
////////////////////////////////////////////////////////
//ray.c
double	ft_generate_ray(t_game *g, double agl, double phi, char *c);
int		ft_round_ray(double round);
////////////////////////////////////////////////////////
//RayCaster

////////////////////////////////////////////////////////
//Minimap
void	ft_print_minimap(t_game *g);
////////////////////////////////////////////////////////
//pintar el minimapa y de ocultar las parte no observables

#endif
