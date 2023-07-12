/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:48:54 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/11 17:14:06 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	img_fail(t_game *g)
{
	if (!g->texture_box_close || !g->texture_box_open || !g->texture_floor
		|| !g->texture_ring || !g->texture_tailsdown || !g->texture_tailsleft
		|| !g->texture_tailsright || !g->texture_tailsup || !g->texture_wall
		|| !g->img_box_close || !g->img_box_open || !g->img_floor
		|| !g->img_ring || !g->img_tailsdown || !g->img_tailsleft
		|| !g->img_tailsright || !g->img_tailsup || !g->img_wall)
		return (FALSE);
	return (TRUE);
}

int	initialize_s_img(t_game *g)
{
	g->texture_box_close = mlx_load_png("./tiles/boxclose.png");
	g->texture_box_open = mlx_load_png("./tiles/boxopen.png");
	g->texture_floor = mlx_load_png("./tiles/floor.png");
	g->texture_ring = mlx_load_png("./tiles/ring.png");
	g->texture_tailsdown = mlx_load_png("./tiles/tailsdown.png");
	g->texture_tailsleft = mlx_load_png("./tiles/tailsleft.png");
	g->texture_tailsright = mlx_load_png("./tiles/tailsright.png");
	g->texture_tailsup = mlx_load_png("./tiles/tailsup.png");
	g->texture_wall = mlx_load_png("./tiles/wall.png");
	g->img_box_close = mlx_texture_to_image(g->mlx, g->texture_box_close);
	g->img_box_open = mlx_texture_to_image(g->mlx, g->texture_box_open);
	g->img_floor = mlx_texture_to_image(g->mlx, g->texture_floor);
	g->img_ring = mlx_texture_to_image(g->mlx, g->texture_ring);
	g->img_tailsdown = mlx_texture_to_image(g->mlx, g->texture_tailsdown);
	g->img_tailsleft = mlx_texture_to_image(g->mlx, g->texture_tailsleft);
	g->img_tailsright = mlx_texture_to_image(g->mlx, g->texture_tailsright);
	g->img_tailsup = mlx_texture_to_image(g->mlx, g->texture_tailsup);
	g->img_wall = mlx_texture_to_image(g->mlx, g->texture_wall);
	clean_textures(g);
	if (img_fail(g) == FALSE)
		return (FALSE);
	return (TRUE);
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
