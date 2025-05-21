/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:11:20 by maborges          #+#    #+#             */
/*   Updated: 2025/05/21 15:35:18 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	try_move(t_data *data, int new_x, int new_y)
{
	char	next_tile;

	printf("try_move called with new_x=%d, new_y=%d\n", new_x, new_y);
	if (new_x < 0 || new_x >= data->map.width
		|| new_y < 0 || new_y >= data->map.height)
		return ;
	next_tile = data->map.grid[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		data->map.player.collected++;
		data->map.grid[new_y][new_x] = '0';
	}
	if (next_tile == 'E')
	{
		if (data->map.player.collected == data->map.total_collect)
		{
			printf("You won in %d moves!\n", ++data->map.player.moves); //trocar ft_printf
			destroy_win(data);
			return ;
		}
		else
			return ;
	}
	data->map.grid[data->map.player.y][data->map.player.x] = '0';
	draw_tile(data, data->map.player.y, data->map.player.x);
	data->map.player.x = new_x;
	data->map.player.y = new_y;
	data->map.grid[new_y][new_x] = 'P';
	data->map.player.moves++;
	printf("Moves: %d\n", data->map.player.moves);
	// Draw both positions
	draw_tile(data, new_y, new_x);
	// Redraw the entire map
	for (int i = 0; i < data->map.height; i++)
    	for (int j = 0; j < data->map.width; j++)
        	draw_tile(data, i, j);
}


int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroy_win(data);
	else if (keycode == 65362) // Up arrow key
	{
		printf("Up arrow key pressed\n");
		try_move(data, data->map.player.x, data->map.player.y - 1);
	}
	else if (keycode == 65364) // Down arrow key
		try_move(data, data->map.player.x, data->map.player.y + 1);
	else if (keycode == 65361) // Left arrow key
		try_move(data, data->map.player.x - 1, data->map.player.y);
	else if (keycode == 65363) // Right arrow key
		try_move(data, data->map.player.x + 1, data->map.player.y);
	else
		printf("Key %d pressed\n", keycode);
	return (0);
}
