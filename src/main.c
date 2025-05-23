/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:22:28 by maborges          #+#    #+#             */
/*   Updated: 2025/05/23 17:35:11 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	file_check(char *filepath)
{
	int	len;

	if (!filepath)
		return (0);
	len = ft_strlen(filepath);
	if (len <= 4)
		return (0);
	if (!ft_strnstr(filepath, ".ber", len))
		return (0);
	if (filepath[len - 4] != '.')
		return (0);
	if (filepath[len - 3] != 'b')
		return (0);
	if (filepath[len - 2] != 'e')
		return (0);
	if (filepath[len - 1] != 'r')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		simple_error_msg("usage: ./so_long <map-file.ber>\n");
	if (!file_check(av[1]))
		simple_error_msg("File does not exist or has wrong format\n");
	if (!load_map(av[1], &data.map))
	{
		destroy_win(&data);
		error_handler("Map loading failed\n", &data.map);
	}
	data.ptr = mlx_init();
	if (!data.ptr)
		return (free_map(&data.map), 1);
	data.win = mlx_new_window(data.ptr, data.map.width * TILE,
			data.map.height * TILE, "So Long");
	if (!data.win)
		return (free_map(&data.map), free(data.ptr), data.ptr = NULL, 1);
	load_img(&data);
	mlx_hook(data.win, 2, 1L<<0, keypress, &data); //Register key hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, destroy_win, &data); // Register destroy hook
	mlx_loop(data.ptr); // loop over the MLX pointer
	return (0);
}
