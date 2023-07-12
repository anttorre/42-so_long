/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:11:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/12 11:03:23 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->moves = 0;
}

static int	main1(t_game *game)
{
	if (initialize_s_img(game) == FALSE)
		return (free(game), EXIT_FAILURE);
	if (set_images_to_game(game) == FALSE)
		return (free(game), EXIT_FAILURE);
	mlx_key_hook(game->mlx, &p_move, game);
	return (TRUE);
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int32_t	main(int argc, char **av)
{
	t_game	*game;

	atexit(ft_leaks);
	if (argc == 1 || argc > 2)
		return (ft_printf("Error: Introduzca un mapa.\n"), EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	initialize_s_game(game);
	if (read_map(av[1], game) == FALSE)
		return (free(game), EXIT_FAILURE);
	if (check_map(game) == FALSE)
		return (free(game), EXIT_FAILURE);
	game->mlx = mlx_init(game->col * 50, game->row * 50, "SO LONG", true);
	if (!game->mlx)
		return (free(game), EXIT_FAILURE);
	if (main1(game) == FALSE)
		return (free(game), EXIT_FAILURE);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free(game), EXIT_SUCCESS);
}
