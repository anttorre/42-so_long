/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:13:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/13 12:13:04 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
/*-------INCLUDES-------*/
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define WIDTH 50
# define HEIGHT 50

/*-------STRUCTS-------*/
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
	t_point			box;
	int				items;
	int				p;
	int				e;
	int				items_cpy;
	int				e_cpy;
	int				moves;
	int				monster_move;
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
	mlx_texture_t	*texture_e1;
	mlx_image_t		*img_e1;
	mlx_texture_t	*texture_e2;
	mlx_image_t		*img_e2;
}					t_game;

/*------PROTOYPES-------*/
int					read_map(char *map_name, t_game *game);
int					check_extension(char *map_name);
int					check_map(t_game *game);
int					set_images_to_game(t_game *game);
void				p_move(mlx_key_data_t keydata, void *param);
void				free_maps(t_game *g);
void				clean_textures(t_game *g);
int					img_fail(t_game *g);
void				monster_sprite(t_game *g);
void				monster_sprite1(t_game *g);
void	put_nbr(t_game *g);


#endif