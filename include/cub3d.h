/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:38:49 by lgaudin           #+#    #+#             */
/*   Updated: 2023/10/14 14:41:29 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define PI M_PI
# define WIDTH 1024
# define HEIGHT 1024

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
	char			**map;
	char			**only_map;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	int				*f_color;
	int				*c_color;
	int				x_player;
	int				y_player;
	double			r_limit;
	double			c_limit;
	double			x_pos;
	double			y_pos;
	double			x_delta;
	double			y_delta;
	double			angle;
	double			t_location;
}					t_game;

typedef struct s_ray
{
	double			x_ray;
	double			y_ray;
	double			x_dis;
	double			y_dis;
	double			x_h;
	double			y_h;
	double			ap_angle;
	int				i;
	int				j;
	double			tpm;
}					t_ray;

typedef struct s_draw
{
	int				i;
	int				j;
	double			k;
	double			n;
	char			c;
	double			t;
}					t_draw;

/*MAIN.C*/
void				ft_free(t_game *game);
void				ft_error(int e);
double				ft_get_ray_angle(int i);

/*FT_UTILS.C*/
char				**ft_split(char const *s, char c);
char				*ft_strdup(char *s1);
void				ft_strcmp_ext(char *map, char *cmp);

/*FT_READ_CHECK.C*/
void				ft_read_map(char *map, t_game *game);
void				ft_check_newline(char *s, t_game *game);
void				ft_get_fcolor(t_game *g, char *s);
void				ft_get_ccolor(t_game *g, char *s);
void				ft_get_parameters(t_game *game);

/*FT_GET_ALL_PARAMETERS.C*/
void				ft_get_no_so(t_game *game, int i, int j, int *bigger);
void				ft_get_we_ea(t_game *game, int i, int j, int *bigger);
void				ft_get_c_f(t_game *game, int i, int j, int *bigger);

/*FT_CHECK_MAP.C*/
void				ft_check_color(char *s, char c);
void				ft_check_parameters(t_game *game);
void				ft_check_texture_format(char *s, char *f, t_game *g, int x);
void				ft_texture_route(t_game *g, int x, char *cpy);
void				ft_check_texture(char *rute, t_game *g, int x);

/*FT_CHECK_MAP_FORMAT.C*/
void				ft_player_pov(t_game *game);
void				ft_check_map(t_game *game, int start);
void				ft_check_borders(t_game *g, int b);

//hooks
void				ft_hook(void *param);
void				ft_print_screen(t_game *g);
////////////////////////////////////////////////////////
//ray.c
double				ft_generate_ray(t_game *g, double agl, double phi, char *c);
int					ft_round_ray(double round);
double				ft_get_angle(double agl);
////////////////////////////////////////////////////////
//RayCaster
void				init_ray(t_ray *r, t_game *g, double agl);
void				first_ray_loop(t_ray *r, t_game *g);
void				second_init_ray(t_ray *r, t_game *g);
void				second_ray_loop(t_ray *r, t_game *g);
double				determine_return(t_ray *r, t_game *g, double phi, char *c);

////////////////////////////////////////////////////////
//Minimap
void				ft_print_minimap(t_game *g);
////////////////////////////////////////////////////////
//pintar el minimapa y de ocultar las parte no observables

// ft_draw_utils.c
void				draw_sky(t_game *g, t_draw *d);
void				draw_floor(t_game *g, t_draw *d);
void				draw_orientation(t_game *g, t_draw *d);

// ft_movements.c
void				move_forward(t_game *g);
void				move_backward(t_game *g);
void				move_right(t_game *g);
void				move_left(t_game *g);

#endif
