/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:48:54 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/06 19:52:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	img_fail(t_img *i)
{
	if (!i->texture_box_close || !i->texture_box_open || !i->texture_floor
		|| !i->texture_ring || !i->texture_tailsdown || !i->texture_tailsleft
		|| !i->texture_tailsright || !i->texture_tailsup || !i->texture_wall
		|| !i->img_box_close || !i->img_box_open || !i->img_floor
		|| !i->img_ring || !i->img_tailsdown || !i->img_tailsleft
		|| !i->img_tailsright || !i->img_tailsup || !i->img_wall)
		return (FALSE);
	return (TRUE);
}

int	initialize_s_img(t_game *game, t_img *i)
{
	i->texture_box_close = mlx_load_png("./tiles/boxclose.png");
	i->texture_box_open = mlx_load_png("./tiles/boxopen.png");
	i->texture_floor = mlx_load_png("./tiles/floor.png");
	i->texture_ring = mlx_load_png("./tiles/ring.png");
	i->texture_tailsdown = mlx_load_png("./tiles/tailsdown.png");
	i->texture_tailsleft = mlx_load_png("./tiles/tailsleft.png");
	i->texture_tailsright = mlx_load_png("./tiles/tailsright.png");
	i->texture_tailsup = mlx_load_png("./tiles/tailsup.png");
	i->texture_wall = mlx_load_png("./tiles/wall.png");
	i->img_box_close = mlx_texture_to_image(game->mlx, i->texture_box_close);
	i->img_box_open = mlx_texture_to_image(game->mlx, i->texture_box_open);
	i->img_floor = mlx_texture_to_image(game->mlx, i->texture_floor);
	i->img_ring = mlx_texture_to_image(game->mlx, i->texture_ring);
	i->img_tailsdown = mlx_texture_to_image(game->mlx, i->texture_tailsdown);
	i->img_tailsleft = mlx_texture_to_image(game->mlx, i->texture_tailsleft);
	i->img_tailsright = mlx_texture_to_image(game->mlx, i->texture_tailsright);
	i->img_tailsup = mlx_texture_to_image(game->mlx, i->texture_tailsup);
	i->img_wall = mlx_texture_to_image(game->mlx, i->texture_wall);
	if (img_fail(i) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	set_images_to_game(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col)
		{
			if (game->map_area[i][j] == '1')
			{
				if (mlx_image_to_window(game->mlx, img->img_wall, j * 50, i
						* 50) < 0)
					error();
			}
			if (game->map_area[i][j] == '0')
			{
				if (mlx_image_to_window(game->mlx, img->img_floor, j * 50, i
						* 50) < 0)
					error();
			}
			if (game->map_area[i][j] == 'E')
			{
				if (mlx_image_to_window(game->mlx, img->img_floor, j * 50, i
						* 50) < 0)
					error();
				if (mlx_image_to_window(game->mlx, img->img_box_close, j * 50, i
						* 50) < 0)
					error();
			}
			if (game->map_area[i][j] == 'C')
			{
				if (mlx_image_to_window(game->mlx, img->img_floor, j * 50, i
						* 50) < 0)
					error();
				if (mlx_image_to_window(game->mlx, img->img_ring, j * 50, i
						* 50) < 0)
					error();
			}
			if (game->map_area[i][j] == 'P')
			{
				if (mlx_image_to_window(game->mlx, img->img_floor, j * 50, i
						* 50) < 0)
					error();
				if (mlx_image_to_window(game->mlx, img->img_tailsright, j * 50,
						i * 50) < 0)
					error();
			}
		}
	}
}
