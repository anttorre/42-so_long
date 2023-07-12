/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:26:56 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/12 12:12:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_map1(t_game *game);
static int	check_map2(t_game *game);
static void	valid_way(t_game *game, t_point size, t_point current);

int	check_extension(char *map_name)
{
	int	i;

	i = (ft_strlen(map_name) - 1);
	if (map_name[i] != 'r' || map_name[i - 1] != 'e' || map_name[i - 2] != 'b'
		|| map_name[i - 3] != '.')
	{
		ft_printf("Error: La extension no es válida.\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
	{
		if (game->line_l != ft_strlen(game->map_area[i])
			|| game->col == game->row)
		{
			ft_printf("Error: El mapa no es válido.\n");
			return (FALSE);
		}
	}
	if (check_map1(game) == FALSE)
		return (FALSE);
	if (check_map2(game) == FALSE)
	{
		ft_printf("Error: contenido del mapa incorrecto.\n");
		return (FALSE);
	}
	valid_way(game, (t_point){game->col, game->row}, game->player);
	if (game->e != game->e_cpy || game->items != game->items_cpy)
		return (ft_printf("Error: No hay un camino válido.\n"), FALSE);
	game->items = 0;
	return (TRUE);
}

static int	check_map1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < game->col)
	{
		if (game->map_area[0][j] != '1' || game->map_area[game->row
			- 1][j] != '1')
		{
			ft_printf("Error: Mapa inválido. No hay paredes suficientes.\n");
			return (FALSE);
		}
	}
	while (++i < (game->row - 1))
	{
		if (game->map_area[i][0] != '1' || game->map_area[i][game->col
			- 1] != '1')
		{
			ft_printf("Error: Mapa inválido. No hay paredes suficientes.\n");
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	check_map2(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col)
		{
			if (game->map_area[i][j] == 'E')
				game->e++;
			else if (game->map_area[i][j] == 'P')
			{
				game->p++;
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->map_area[i][j] == 'C')
				game->items++;
		}
	}
	if (game->e != 1 || game->p != 1 || game->items < 1)
		return (FALSE);
	return (TRUE);
}

static void	valid_way(t_game *game, t_point size, t_point current)
{
	if (current.x < 0 || current.x >= size.x || current.y < 0
		|| current.y >= size.y || game->map_cpy[current.y][current.x] == '1'
		|| game->map_cpy[current.y][current.x] == '*')
		return ;
	if (game->map_cpy[current.y][current.x] == 'C')
		game->items_cpy++;
	if (game->map_cpy[current.y][current.x] == 'E')
	{	
		game->e_cpy++;
		game->box.x = current.x;
		game-> box.y = current.y;
	}
	game->map_cpy[current.y][current.x] = '*';
	valid_way(game, size, (t_point){current.x - 1, current.y});
	valid_way(game, size, (t_point){current.x + 1, current.y});
	valid_way(game, size, (t_point){current.x, current.y - 1});
	valid_way(game, size, (t_point){current.x, current.y + 1});
}
