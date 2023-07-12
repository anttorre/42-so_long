/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:35:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/12 15:16:03 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	monster_sprite(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map_area[++i])
	{
		j = -1;
		while (g->map_area[i][++j])
		{
			if (g->map_area[i][j] == 'M')
			{
				mlx_image_to_window(g->mlx, g->img_floor, j * 50, i * 50);
				mlx_image_to_window(g->mlx, g->img_e2, j * 50, i * 50);
			}
		}
	}
	g->monster_move = TRUE;
}

void	monster_sprite1(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map_area[++i])
	{
		j = -1;
		while (g->map_area[i][++j])
		{
			if (g->map_area[i][j] == 'M')
			{
				mlx_image_to_window(g->mlx, g->img_floor, j * 50, i * 50);
				mlx_image_to_window(g->mlx, g->img_e1, j * 50, i * 50);
			}
		}
	}
	g->monster_move = FALSE;
}