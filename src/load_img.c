/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:13:26 by maborges          #+#    #+#             */
/*   Updated: 2025/05/21 16:53:06 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_tile(t_data *data, int row, int col)
{
	int	x;
	int	y;

	x = col * TILE;
	y = row * TILE;

	mlx_put_image_to_window(data->ptr, data->win, data->grass.img, x, y);
	if (data->map.grid[row][col] == '1')
		mlx_put_image_to_window(data->ptr, data->win, data->wall.img, x, y);
	else if (data->map.grid[row][col] == 'E')
		mlx_put_image_to_window(data->ptr, data->win, data->house.img, x, y);
	else if (data->map.grid[row][col] == 'P')
		mlx_put_image_to_window(data->ptr, data->win, data->cat.img, x, y);
	else if (data->map.grid[row][col] == 'C')
		mlx_put_image_to_window(data->ptr, data->win, data->chicken.img, x, y);
}

void	load_img(t_data *data)
{
	int	w;
	int	h;
	int	i;
	int	j;

	data->cat.img = mlx_xpm_file_to_image(data->ptr, PATH_CAT, &w, &h);
	data->chicken.img = mlx_xpm_file_to_image(data->ptr, PATH_C, &w, &h);
	data->wall.img = mlx_xpm_file_to_image(data->ptr, PATH_W, &w, &h);
	data->grass.img = mlx_xpm_file_to_image(data->ptr, PATH_G, &w, &h);
	data->house.img = mlx_xpm_file_to_image(data->ptr, PATH_H, &w, &h);
	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < data->map.width)
		{
			draw_tile(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}



