/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:22:28 by maborges          #+#    #+#             */
/*   Updated: 2025/05/16 20:16:25 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	keypress(int keycode, t_data *data)
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
	int		i;

	if (ac != 2)
		error_handler("usage: ./so_long <map-file.ber>\n");
	if (!load_map(av[1], &data.map))
		error_handler("Map loading failed\n");
	i = 0;
	while (i < data.map.height)
	{
		if (data.map.grid[i])
			printf("%s\n", data.map.grid[i]);
		else
			printf("NULL\n");
		i++;
	}
	data.ptr = mlx_init();
	if (!data.ptr)
		return (free_map(&data.map), 1);
	data.win = mlx_new_window(data.ptr, data.map.width * TILE,
			data.map.height * TILE, "So Long");
	if (!data.win)
		return (free_map(&data.map), free(data.ptr), data.ptr = NULL, 1);
	load_img(&data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, keypress, &data); //Register key release hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, destroy_win, &data); // Register destroy hook
	mlx_loop(data.ptr); // loop over the MLX pointer
	return (0);
}
