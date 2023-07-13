/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:44:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/13 12:58:56 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	keypress(t_game *g, int new_x, int new_y, void *img_tails);
static void	move_player_c(t_game *g, int new_x, int new_y, void *img_tails);
static void	move_player_e(t_game *g, int new_x, int new_y, void *img_tails);
static void	move_player_1(t_game *g, int new_x, int new_y, void *img_tails);

void	p_move(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_maps(g);
		mlx_close_window(g->mlx);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		keypress(g, g->player.x - 1, g->player.y, g->img_tailsleft);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		keypress(g, g->player.x + 1, g->player.y, g->img_tailsright);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		keypress(g, g->player.x, g->player.y + 1, g->img_tailsdown);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		keypress(g, g->player.x, g->player.y - 1, g->img_tailsup);
}

static void	keypress(t_game *g, int new_x, int new_y, void *img_tails)
{
	if (g->map_area[new_y][new_x] == 'C')
		move_player_c(g, new_x, new_y, img_tails);
	else if (g->map_area[new_y][new_x] == 'E' && g->items == g->items_cpy)
	{
		free_maps(g);
		mlx_close_window(g->mlx);
	}
	else if (g->map_area[new_y][new_x] == 'E')
		move_player_e(g, new_x, new_y, img_tails);
	else if (g->map_area[new_y][new_x] != '1')
		move_player_1(g, new_x, new_y, img_tails);
}

static void	move_player_c(t_game *g, int new_x, int new_y, void *img_tails)
{
	mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50, g->player.y
		* 50);
	if (g->map_area[g->player.y][g->player.x] == 'E')
		mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
			g->player.y * 50);
	g->player.x = new_x;
	g->player.y = new_y;
	g->map_area[g->player.y][g->player.x] = '0';
	mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50, g->player.y
		* 50);
	mlx_image_to_window(g->mlx, img_tails, g->player.x * 50, g->player.y * 50);
	g->items++;
	g->moves++;
	if (g->items == g->items_cpy)
		mlx_image_to_window(g->mlx, g->img_box_open, g->box.x * 50, g->box.y
			* 50);
	ft_printf("Nº movimientos: %d\n", g->moves);
}

static void	move_player_e(t_game *g, int new_x, int new_y, void *img_tails)
{
	mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50, g->player.y
		* 50);
	g->player.x = new_x;
	g->player.y = new_y;
	mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50, g->player.y
		* 50);
	mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50, g->player.y
		* 50);
	mlx_image_to_window(g->mlx, img_tails, g->player.x * 50, g->player.y * 50);
	g->moves++;
	ft_printf("Nº movimientos: %d\n", g->moves);
}

static void	move_player_1(t_game *g, int new_x, int new_y, void *img_tails)
{
	mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50, g->player.y
		* 50);
	if (g->map_area[g->player.y][g->player.x] == 'E')
		mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
			g->player.y * 50);
	g->player.x = new_x;
	g->player.y = new_y;
	mlx_image_to_window(g->mlx, img_tails, g->player.x * 50, g->player.y * 50);
	g->moves++;
	ft_printf("Nº movimientos: %d\n", g->moves);
}
