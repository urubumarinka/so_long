/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:52:53 by maborges          #+#    #+#             */
/*   Updated: 2025/05/15 18:06:27 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	update_flag(char ch, int *flag)
{
	if (ch == 'P')
		flag[0]++;
	else if (ch == 'E')
		flag[1]++;
	else if (ch == 'C')
		flag[2]++;
	else if (ch != '0' && ch != '1')
		error_handler("Map with invalid character");
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
			update_flag(ch, flag);
		}
	}
	if (flag[0] != 1 || flag[1] != 1 || flag[2] < 1)
		error_handler("Map must have 1 P, 1 E, and at least 1 C");
	return (1);
}
