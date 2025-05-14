/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:53 by maborges          #+#    #+#             */
/*   Updated: 2025/05/14 19:15:10 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* //still on pseudo-code to check if map is valid
if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid; */

static int	count_lines(int fd)
{
	char	*line;
	int		count = 0;

	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

static int	fill_grid(int fd, t_map *map, int line_count)
{
	char	*line;
	int		i = 0;

	map->grid = malloc(sizeof(char *) * (line_count + 1));
	if (!map->grid)
		return (0);
	while ((line = get_next_line(fd)))
	{
		map->grid[i] = ft_strtrim(line, "\n"); // remove newline
		free(line);
		if (!map->grid[i])
			return (0);
		i++;
	}
	map->grid[i] = NULL;
	map->height = line_count;
	map->width = ft_strlen(map->grid[0]); // assume rectangle for now
	return (1);
}

int load_map(char *file, t_map *map)
{
	int	fd;
	int	line_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line_count = count_lines(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!fill_grid(fd, map, line_count))
		return (0);
	close(fd);
	printf("Map loaded with %d lines.\n", line_count);
	return (1);
}
