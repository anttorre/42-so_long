/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:11:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/30 17:17:06 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(void)
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

int32_t	main(int argc, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	initialize_s_game(game);
	if (argc == 1 || argc > 2)
	{
		ft_printf("Error: Introduzca un mapa.\n");
		return (free(game), EXIT_FAILURE);
	}
	if (read_map(av[1], game) == FALSE)
		return (free(game), EXIT_FAILURE);
	if (check_map(game) == FALSE)
		return (free(game), EXIT_FAILURE);
	int i = 0;
	while (i < game->row)
	{
		ft_printf("%s\n", game->map_area[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < game->row)
	{
		ft_printf("%s\n", game->map_cpy[i]);
		i++;
	}
	game->mlx = mlx_init(game->col * 50, game->row * 50, "SO LONG", true);
	if (!game->mlx)
		error();
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
