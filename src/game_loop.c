/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:11:20 by maborges          #+#    #+#             */
/*   Updated: 2025/05/19 18:52:56 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	try_move(t_data *data, int new_x, int new_y)
{
	char	next_tile;

	if (new_x < 0 || new_x >= data->map.width
		|| new_y < 0 || new_y >= data->map.height)
		return ;
	printf("try_move called with new_x=%d, new_y=%d\n", new_x, new_y);
	next_tile = data->map.grid[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		data->player.collected++;
		//data->map.grid[new_y][new_x] = '0';
	}
	if (next_tile == 'E')
	{
		if (data->player.collected == data->map.total_collect)
		{
			printf("You won in %d moves!\n", ++data->player.moves); //trocar ft_printf
			destroy_win(data);
			return ;
		}
	}
	draw_tile(data, data->player.y, data->player.x);
	printf("Player at row=%d col=%d\n", data->player.y, data->player.x);
	data->map.grid[data->player.y][data->player.x] = '0';
	data->player.x = new_x;
	data->player.y = new_y;
	data->map.grid[new_y][new_x] = 'P';
	data->player.moves++;
	printf("Moves: %d\n", data->player.moves); //trocar ft_printf
	draw_tile(data, new_y, new_x);
}


int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroy_win(data);
	else if (keycode == 65362) // Up arrow key
		try_move(data, data->player.x, data->player.y - 1);
	else if (keycode == 65364) // Down arrow key
		try_move(data, data->player.x, data->player.y + 1);
	else if (keycode == 65361) // Left arrow key
		try_move(data, data->player.x - 1, data->player.y);
	else if (keycode == 65363) // Right arrow key
		try_move(data, data->player.x + 1, data->player.y);
	else
		printf("Key %d pressed\n", keycode);
	return (0);
}
