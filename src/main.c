/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:22:28 by maborges          #+#    #+#             */
/*   Updated: 2025/05/14 19:19:22 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroy_win(data);
	else if(keycode == XK_Up)
		printf("Up key pressed\n");
	else if(keycode == XK_Down)
		printf("Down key pressed\n");
	else if(keycode == XK_Left)
		printf("Left key pressed\n");
	else if(keycode == XK_Right)
		printf("Right key pressed\n");
	else
		printf("Key %d pressed\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i;

	if(ac != 2)
	{
		printf("usage: %s <map-file.ber>\n", av[0]);
		return (1);
	}
	if(!load_map(av[1], &data.map))
	{
		printf("Error: Failed to load map\n");
		return (1);
	}

	i = 0;
	while(i < data.map.height)
	{
		if(data.map.grid[i])
			printf("%s\n", data.map.grid[i]);
		else
			printf("NULL\n");
		i++;
	}

	data.mlx_con = mlx_init();
	if (!data.mlx_con)
		return (free_map(&data.map), 1);
	data.mlx_win = mlx_new_window(data.mlx_con, WIDTH, HEIGHT, "Hello");
	if (!data.mlx_win)
		return (free_map(&data.map), free(data.mlx_con), data.mlx_con = NULL, 1);
	load_img(&data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, keypress, &data); //Register key release hook
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &destroy_win, &data); // Register destroy hook
	mlx_loop(data.mlx_con); // loop over the MLX pointer
	return (0);
}
