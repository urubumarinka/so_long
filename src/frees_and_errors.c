/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:45:56 by maborges          #+#    #+#             */
/*   Updated: 2025/05/23 19:51:07 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	simple_error_msg(const char *message)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	error_handler(const char *message, t_map *map)
{
	if (map)
		free_map(map);
	if (message)
		ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

void	free_images(t_data *data)
{
	if (data->grass.img)
		mlx_destroy_image(data->ptr, data->grass.img);
	if (data->cat.img)
		mlx_destroy_image(data->ptr, data->cat.img);
	if (data->wall.img)
		mlx_destroy_image(data->ptr, data->wall.img);
	if (data->chicken.img)
		mlx_destroy_image(data->ptr, data->chicken.img);
	if (data->house.img)
		mlx_destroy_image(data->ptr, data->house.img);
}

int	destroy_win(t_data *data)
{
	free_images(data);
	free_map(&data->map);
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	data->ptr = NULL;
	exit(0);
	return (0);
}

