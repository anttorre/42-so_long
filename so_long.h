/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:13:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/30 12:24:16 by anttorre         ###   ########.fr       */
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

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct so_long
{
	mlx_t	*mlx;
	char	**map_area;
	char	**map_cpy;
	size_t	col;
	size_t	line_l;
	size_t	row;
	t_point	player;
	int		items;
	int		p;
	int		e;
	int		items_cpy;
	int		e_cpy;
}			t_game;

void		initialize_s_game(t_game *game);
void		free_map_area(t_game *game, int i);
int			read_map(char *map_name, t_game *game);
int			allocate_map(char *line, t_game *game, int fd, char *map_name);
int			allocate_map1(char *line, t_game *game, int fd, char *map_name);
int			check_map(t_game *game);
int			check_map1(t_game *game);
int			check_map2(t_game *game);
int			check_extension(char *map_name);
void		valid_way(t_game *game, t_point size, t_point current);

#endif