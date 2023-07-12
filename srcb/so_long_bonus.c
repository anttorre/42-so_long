/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:11:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/12 11:53:57 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_s_game(t_game *game)
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

static int	initialize_s_img(t_game *g)
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