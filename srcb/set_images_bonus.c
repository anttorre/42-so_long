/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:48:54 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/13 12:00:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	img_fail(t_game *g)
{
	if (!g->texture_box_close || !g->texture_box_open || !g->texture_floor
		|| !g->texture_ring || !g->texture_tailsdown || !g->texture_tailsleft
		|| !g->texture_tailsright || !g->texture_tailsup || !g->texture_wall
		|| !g->img_box_close || !g->img_box_open || !g->img_floor
		|| !g->img_ring || !g->img_tailsdown || !g->img_tailsleft
		|| !g->img_tailsright || !g->img_tailsup || !g->img_wall
		|| !g->img_e1 || !g->img_e2)
		return (FALSE);
	return (TRUE);
}

void	clean_textures(t_game *g)
{
	mlx_delete_texture(g->texture_box_close);
	mlx_delete_texture(g->texture_box_open);
	mlx_delete_texture(g->texture_floor);
	mlx_delete_texture(g->texture_ring);
	mlx_delete_texture(g->texture_tailsdown);
	mlx_delete_texture(g->texture_tailsleft);
	mlx_delete_texture(g->texture_tailsright);
	mlx_delete_texture(g->texture_tailsup);
	mlx_delete_texture(g->texture_wall);
	mlx_delete_texture(g->texture_e1);
	mlx_delete_texture(g->texture_e2);
}

static int	set_images_to_game1(t_game *game, int i, int j)
{
	if (game->map_area[i][j] == '1')
		if (mlx_image_to_window(game->mlx, game->img_wall, j * 50, i * 50) < 0)
			return (FALSE);
	if (game->map_area[i][j] == '0')
		if (mlx_image_to_window(game->mlx, game->img_floor, j * 50, i * 50) < 0)
			return (FALSE);
	if (game->map_area[i][j] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * 50, i * 50) < 0)
			return (FALSE);
		if (mlx_image_to_window(game->mlx, game->img_box_close, j * 50, i
				* 50) < 0)
			return (FALSE);
	}
	if (game->map_area[i][j] == 'M')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * 50, i * 50) < 0)
			return (FALSE);
		if (mlx_image_to_window(game->mlx, game->img_e1, j * 50, i
				* 50) < 0)
			return (FALSE);
	}
	return (TRUE);
}

static int	set_images_to_game2(t_game *game, int i, int j)
{
	if (game->map_area[i][j] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * 50, i * 50) < 0)
			return (FALSE);
		if (mlx_image_to_window(game->mlx, game->img_ring, j * 50, i * 50) < 0)
			return (FALSE);
	}
	if (game->map_area[i][j] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * 50, i * 50) < 0)
			return (FALSE);
		if (mlx_image_to_window(game->mlx, game->img_tailsright, j * 50, i
				* 50) < 0)
			return (FALSE);
	}
	return (TRUE);
}

int	set_images_to_game(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col)
		{
			if (set_images_to_game1(game, i, j) == FALSE)
				return (FALSE);
			if (set_images_to_game2(game, i, j) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}
