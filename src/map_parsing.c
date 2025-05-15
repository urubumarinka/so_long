/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:53 by maborges          #+#    #+#             */
/*   Updated: 2025/05/15 18:05:48 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
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
		map->grid[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map->grid[i])
			return (0);
		i++;
	}
	map->grid[i] = NULL;
	map->height = line_count;
	map->width = ft_strlen(map->grid[0]);
	return (1);
}

static int	map_validation(t_map *map, int line_count)
{
	int	i;

	i = -1;
	if (line_count < 3 || map->width < 3)
		error_handler("Map is too small");
	while (++i < line_count)
		if ((int)ft_strlen(map->grid[i]) != map->width)
			error_handler("Map is not rectangular");
	i = -1;
	while (++i < map->width)
		if (map->grid[0][i] != '1' || map->grid[line_count - 1][i] != 1)
			error_handler("Map borders are not valid");
	i = -1;
	while(++i < line_count)
		if(map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			error_handler("Map borders are not valid");
	return(1);

}

int	load_map(char *file, t_map *map)
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
	if (!map_validation(map, line_count))
		return (0);
	if (!check_map_elements(map))
		return (0);
	printf("Map loaded with %d lines.\n", line_count); //tirar isso dps
	return (1);
}
