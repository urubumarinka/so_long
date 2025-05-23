/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:52:53 by maborges          #+#    #+#             */
/*   Updated: 2025/05/23 18:29:06 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	update_flag(char ch, int *flag, t_map *map)
{
	if (ch == 'P')
		flag[0]++;
	else if (ch == 'E')
		flag[1]++;
	else if (ch == 'C')
		flag[2]++;
	else if (ch != '0' && ch != '1')
		error_handler("Map with invalid character", map);
}

int	check_map_elements(t_map *map)
{
	int		i;
	int		j;
	char	ch;
	int		flag[3];

	i = -1;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ch = map->grid[i][j];
			update_flag(ch, flag, map);
			if (ch == 'P')
			{
				map->player.x = j;
				map->player.y = i;
			}
		}
	}
	map->exits = flag[1];
	map->total_collect = flag[2];
	map->player.moves = 0;
	map->player.collected = 0;
	if (flag[0] != 1 || flag[1] != 1 || flag[2] < 1)
		error_handler("Map must have 1 P, 1 E, and at least 1 C", map);
	return (1);
}

static char	**copy_map(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));

	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
			{
				free(copy[i]);
				copy[i] = NULL;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **copy_map, int x, int y, int *flag)
{
	if (y < 0 || x < 0)
		return ;
	if (!copy_map[y] || x >= (int)ft_strlen(copy_map[y]))
		return ;
	if (copy_map[y][x] == '1')
		return ;
	else if (copy_map[y][x] == 'C')
		flag[0]++;
	else if (copy_map[y][x] == 'E')
		flag[1]++;
	copy_map[y][x] = '1';
	flood_fill(copy_map, x + 1, y, flag);
	flood_fill(copy_map, x - 1, y, flag);
	flood_fill(copy_map, x, y + 1, flag);
	flood_fill(copy_map, x, y - 1, flag);
}

int	validate_map_path(t_map *map)
{
	char	**copy;
	int		flag[2];
	int		i;

	copy = copy_map(map->grid, map->height);
	if (!copy)
	{
		i = -1;
		while (++i < map->height)
			free(copy[i]);
		return (free(copy), 0);
	}
	flag[0] = 0;
	flag[1] = 0;
	flood_fill(copy, map->player.x, map->player.y, flag);
	i = -1;
	while (++i < map->height)
		free(copy[i]);
	free(copy);
	return (flag[0] == map->total_collect && flag[1] == map->exits);
}

