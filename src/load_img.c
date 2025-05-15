/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:13:26 by maborges          #+#    #+#             */
/*   Updated: 2025/05/15 15:08:17 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_img(t_data *data)
{
	int	width;
	int	height;
	int	i = 0;
	// Load textures from XPM files
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_con, PATH_CAT, &width, &height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_con, PATH_CHICKEN, &width, &height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_con, PATH_FARMTILE, &width, &height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_con, PATHGRASS, &width, &height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_con, PATH_HOUSE, &width, &height);

	// Check if all textures were loaded successfully
	while (i < 5)
		if (!data->textures[i++])
			error_handler("Error: Failed to load texture");

	// Display the loaded image in the window
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->textures[0], 0, 0);
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->textures[1], 32, 0);
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->textures[2], 64, 0);
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->textures[3], 96, 0);
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->textures[4], 128, 0);
}


