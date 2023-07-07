/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:13:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/07 13:18:41 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*-------INCLUDES-------*/
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define WIDTH 50
# define HEIGHT 50

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct so_long
{
	mlx_t			*mlx;
	char			**map_area;
	char			**map_cpy;
	int				col;
	size_t			line_l;
	int				row;
	t_point			player;
	int				items;
	int				p;
	int				e;
	int				items_cpy;
	int				e_cpy;
}					t_game;

typedef struct s_img
{
	mlx_texture_t	*texture_box_close;
	mlx_image_t		*img_box_close;
	mlx_texture_t	*texture_box_open;
	mlx_image_t		*img_box_open;
	mlx_texture_t	*texture_floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*texture_ring;
	mlx_image_t		*img_ring;
	mlx_texture_t	*texture_tailsdown;
	mlx_image_t		*img_tailsdown;
	mlx_texture_t	*texture_tailsleft;
	mlx_image_t		*img_tailsleft;
	mlx_texture_t	*texture_tailsup;
	mlx_image_t		*img_tailsup;
	mlx_texture_t	*texture_tailsright;
	mlx_image_t		*img_tailsright;
	mlx_texture_t	*texture_wall;
	mlx_image_t		*img_wall;
}					t_img;

void				initialize_s_game(t_game *game);
void				free_map_area(t_game *game, int i);
int					read_map(char *map_name, t_game *game);
int					allocate_map(char *line, t_game *game, int fd,
						char *map_name);
int					allocate_map1(char *line, t_game *game, int fd,
						char *map_name);
int					check_map(t_game *game);
int					check_map1(t_game *game);
int					check_map2(t_game *game);
int					check_extension(char *map_name);
void				valid_way(t_game *game, t_point size, t_point current);
int					set_images_to_game(t_game *game, t_img *img);
int					initialize_s_img(t_game *game, t_img *images);
void				error(void);

#endif