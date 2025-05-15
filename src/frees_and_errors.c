/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:45:56 by maborges          #+#    #+#             */
/*   Updated: 2025/05/15 18:13:13 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_handler(const char *message)
{
	printf("Error: %s\n", message); // change to ft_printf
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i = 0;

	while (map->grid && map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}
int	destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx_con, data->mlx_win);
	mlx_destroy_display(data->mlx_con);
	free_map(&data->map);
	free(data->mlx_con);
	data->mlx_con = NULL;
	exit(0);
	return (0);
}

