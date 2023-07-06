/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:35:51 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/06 19:51:19 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_area(t_game *game, int i)
{
	int	j;

	j = i;
	if (game->map_area)
	{
		while (--i >= 0)
			free(game->map_area[i]);
		free(game->map_area);
	}
	if (game->map_cpy)
	{
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
		return (free(line), FALSE);
	}
	while (line != NULL)
	{
		game->row++;
		line = get_next_line(fd);
	}
	game->map_area = malloc(game->row * sizeof(char *));
	game->map_cpy = malloc(game->row * sizeof(char *));
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
		game->map_area[i] = malloc(game->col * sizeof(char));
		game->map_cpy[i] = malloc(game->col * sizeof(char));
		if (!game->map_area[i] || !game->map_cpy[i])
			return (free_map_area(game, i), free(line), FALSE);
		ft_strlcpy(game->map_area[i], line, ft_strlen(line)
			+ (line[ft_strlen(line) - 1] != '\n'));
		ft_strlcpy(game->map_cpy[i], line, ft_strlen(line)
			+ (line[ft_strlen(line) - 1] != '\n'));
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (free(line), TRUE);
}
