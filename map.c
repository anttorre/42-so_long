/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:35:51 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:40 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	free_maps(t_game *g)
{
	char	**map_area_start;
	char	**map_cpy_start;
	char	**map_area_start;
	char	**map_cpy_start;

	if (!g->map_area && !g->map_cpy)
		return ;
	map_area_start = g->map_area;
	map_cpy_start = g->map_cpy;
	for (int i = 0; g->map_area[i] != NULL; i++)
	{
		free(g->map_area[i]);
	}
	free(map_area_start);
	for (int i = 0; g->map_cpy[i] != NULL; i++)
	{
		free(g->map_cpy[i]);
	}
	free(map_cpy_start);
} */
void	free_maps(t_game *g)
{
	char	**map_area_start;
	char	**map_cpy_start;

	if (!g->map_area && !g->map_cpy)
		return ;
	map_area_start = g->map_area;
	map_cpy_start = g->map_cpy;
	while (*(g->map_area))
	{
		free(*(g->map_area));
		g->map_area++;
	}
	free(map_area_start);
	while (*(g->map_cpy))
	{
		free(*(g->map_cpy));
		g->map_cpy++;
	}
	free(map_cpy_start);
}
/* void	free_maps(t_game *g)
{
	int	j;

	i = 0;
	if (!g->map_area && !g->map_cpy)
		return ;
	while (i < g->row)
	{
		free(g->map_area[i]);
		i++;
	}
	free(g->map_area);
	i = 0;
	while (i < g->row)
	{
		free(g->map_cpy[i]);
		i++;
	}
	free(g->map_cpy);
} */
void	free_map_area(t_game *game, int i)
{
	int	j;

	j = i;
	if (game->map_area)
	{
		if (game->map_area[i] != NULL)
			free(game->map_area[i]);
		while (--i >= 0)
			free(game->map_area[i]);
		free(game->map_area);
	}
	if (game->map_cpy)
	{
		if (game->map_cpy[j] != NULL)
			free(game->map_cpy[j]);
		while (--j >= 0)
			free(game->map_cpy[j]);
		free(game->map_cpy);
	}
}

int	read_map(char *map_name, t_game *game)
{
	int		fd;
	char	*line;

	line = NULL;
	if (check_extension(map_name) == FALSE)
		return (FALSE);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: No se encontro el fichero o no se pudo abrir.\n");
		return (FALSE);
	}
	if (allocate_map(line, game, fd, map_name) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	allocate_map(char *line, t_game *game, int fd, char *map_name)
{
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error: Mapa vacío.\n");
		return (FALSE);
	}
	while (line != NULL)
	{
		game->row++;
		free(line);
		line = get_next_line(fd);
	}
	game->map_area = ft_calloc((game->row + 1), sizeof(char *));
	game->map_cpy = ft_calloc((game->row + 1), sizeof(char *));
	if (!game->map_area || !game->map_cpy)
		return (free(line), FALSE);
	close(fd);
	if (allocate_map1(line, game, fd, map_name) == FALSE)
		return (free(line), FALSE);
	return (free(line), TRUE);
}

int	allocate_map1(char *line, t_game *game, int fd, char *map_name)
{
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	game->line_l = (ft_strlen(line) - 1);
	while (line != NULL)
	{
		game->col = ft_strlen(line);
		game->map_area[i] = ft_calloc(game->col + (line[game->col - 1] != '\n'),
				sizeof(char));
		game->map_cpy[i] = ft_calloc(game->col + (line[game->col - 1] != '\n'),
				sizeof(char));
		if (!game->map_area[i] && !game->map_cpy[i])
			return (free_map_area(game, i), free(line), FALSE);
		ft_strlcpy(game->map_area[i], line, game->col + (line[game->col
				- 1] != '\n'));
		ft_strlcpy(game->map_cpy[i], line, ft_strlen(line) + (line[game->col
				- 1] != '\n'));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map_area[i] = NULL;
	game->map_cpy[i] = NULL;
	close(fd);
	return (free(line), TRUE);
}
