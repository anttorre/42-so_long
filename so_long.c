/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:11:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/07 14:38:50 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	initialize_s_game(t_game *game)
{
	game->col = 0;
	game->row = 0;
	game->line_l = 0;
	game->items = 0;
	game->e = 0;
	game->p = 0;
	game->items_cpy = 0;
	game->e_cpy = 0;
}

static int	main1(t_game *game, t_img *images)
{
	if (initialize_s_img(game, images) == FALSE)
		return (free(game), free(images), EXIT_FAILURE);
	if (set_images_to_game(game, images) == FALSE)
		return (free(game), free(images), EXIT_FAILURE);
	return (TRUE);
}

int32_t	main(int argc, char **av)
{
	t_game	*game;
	t_img	*images;

	if (argc == 1 || argc > 2)
		return (ft_printf("Error: Introduzca un mapa.\n"), EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	images = malloc(sizeof(t_img));
	if (!game || !images)
		return (free(game), free(images), EXIT_FAILURE);
	initialize_s_game(game);
	if (read_map(av[1], game) == FALSE)
		return (free(game), free(images), EXIT_FAILURE);
	if (check_map(game) == FALSE)
		return (free(game), free(images), EXIT_FAILURE);
	game->mlx = mlx_init(game->col * 50, game->row * 50, "SO LONG", true);
	if (!game->mlx)
		return (free(game), free(images), EXIT_FAILURE);
	if (main1(game, images) == FALSE)
		return (free(game), free(images), EXIT_FAILURE);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free(game), free(images), EXIT_SUCCESS);
}
