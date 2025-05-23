/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:53 by maborges          #+#    #+#             */
/*   Updated: 2025/05/23 17:49:02 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!line)
			return (0);
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	fill_grid(int fd, t_map *map, int line_count)
{
	char	*line;
	int		i;

	map->grid = malloc(sizeof(char *) * (line_count + 1));
	if (!map->grid)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->grid[i] = ft_strtrim(line, "\n");
		if (!map->grid[i])
			return (free_map(map), 0);
		free(line);
		line = NULL;
		i++;
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	map->height = line_count;
	if (map->grid[0])
		map->width = ft_strlen(map->grid[0]);
	else
		map->width = 0;
	return (1);
}

static int	map_validation(t_map *map, int line_count)
{
	int	i;

	i = -1;
	if (line_count < 3 || map->width < 3)
		error_handler("Map is too small", map);
	while (++i < line_count)
		if ((int)ft_strlen(map->grid[i]) != map->width)
			error_handler("Map is not rectangular", map);
	i = -1;
	while (++i < map->width)
		if (map->grid[0][i] != '1' || map->grid[line_count - 1][i] != '1')
			error_handler("Map borders are not valid", map);
	i = -1;
	while (++i < line_count)
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			error_handler("Map borders are not valid", map);
	return (1);

}

int	load_map(char *file, t_map *map)
{
	int	fd;
	int	line_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (simple_error_msg("file does not exist"), 0);
	line_count = count_lines(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!fill_grid(fd, map, line_count))
		return (free_map(map), 0);
	close(fd);
	if (!map_validation(map, line_count))
		return (free_map(map), 0);
	if (!check_map_elements(map))
		return (free_map(map), 0);
	if (!validate_map_path(map))
		return (error_handler("Map is not valid", map), 0);
	return (1);
}
