/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:44:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/10 15:57:32 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_move(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g->mlx);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (g->map_area[g->player.y][g->player.x - 1] == 'C')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.x -= 1;
			g->map_area[g->player.y][g->player.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsleft, g->player.x * 50,
				g->player.y * 50);
			g->items++;
			g->moves++;
			if (g->items == g->items_cpy)
				mlx_image_to_window(g->mlx, g->img_box_open, g->box.x * 50,
					g->box.y * 50);
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y][g->player.x - 1] == 'E'
				&& g->items == g->items_cpy)
			mlx_close_window(g->mlx);
		else if (g->map_area[g->player.y][g->player.x - 1] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			g->player.x -= 1;
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsleft, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y][g->player.x - 1] != '1')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.x -= 1;
			mlx_image_to_window(g->mlx, g->img_tailsleft, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (g->map_area[g->player.y][g->player.x + 1] == 'C')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.x += 1;
			g->map_area[g->player.y][g->player.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsright, g->player.x * 50,
				g->player.y * 50);
			g->items++;
			g->moves++;
			if (g->items == g->items_cpy)
				mlx_image_to_window(g->mlx, g->img_box_open, g->box.x * 50,
					g->box.y * 50);
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y][g->player.x + 1] == 'E'
				&& g->items == g->items_cpy)
			mlx_close_window(g->mlx);
		else if (g->map_area[g->player.y][g->player.x + 1] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			g->player.x += 1;
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsright, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y][g->player.x + 1] != '1')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.x += 1;
			mlx_image_to_window(g->mlx, g->img_tailsright, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (g->map_area[g->player.y + 1][g->player.x] == 'C')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.y += 1;
			g->map_area[g->player.y][g->player.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsdown, g->player.x * 50,
				g->player.y * 50);
			g->items++;
			g->moves++;
			if (g->items == g->items_cpy)
				mlx_image_to_window(g->mlx, g->img_box_open, g->box.x * 50,
					g->box.y * 50);
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y + 1][g->player.x] == 'E'
				&& g->items == g->items_cpy)
			mlx_close_window(g->mlx);
		else if (g->map_area[g->player.y + 1][g->player.x] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			g->player.y += 1;
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsdown, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y + 1][g->player.x] != '1')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.y += 1;
			mlx_image_to_window(g->mlx, g->img_tailsdown, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (g->map_area[g->player.y - 1][g->player.x] == 'C')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.y -= 1;
			g->map_area[g->player.y][g->player.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsup, g->player.x * 50,
				g->player.y * 50);
			g->items++;
			g->moves++;
			if (g->items == g->items_cpy)
				mlx_image_to_window(g->mlx, g->img_box_open, g->box.x * 50,
					g->box.y * 50);
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y - 1][g->player.x] == 'E'
				&& g->items == g->items_cpy)
			mlx_close_window(g->mlx);
		else if (g->map_area[g->player.y - 1][g->player.x] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			g->player.y -= 1;
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
				g->player.y * 50);
			mlx_image_to_window(g->mlx, g->img_tailsup, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
		else if (g->map_area[g->player.y - 1][g->player.x] != '1')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->player.x * 50,
				g->player.y * 50);
			if (g->map_area[g->player.y][g->player.x] == 'E')
				mlx_image_to_window(g->mlx, g->img_box_close, g->player.x * 50,
					g->player.y * 50);
			g->player.y -= 1;
			mlx_image_to_window(g->mlx, g->img_tailsup, g->player.x * 50,
				g->player.y * 50);
			g->moves++;
			ft_printf("Nº movimientos: %d\n", g->moves);
		}
	}
}
