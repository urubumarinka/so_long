/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:22:28 by maborges          #+#    #+#             */
/*   Updated: 2025/05/12 18:47:19 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx_con, data->mlx_win);
	mlx_destroy_display(data->mlx_con);
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

int	main(void)
{
	t_data	data;

	data.mlx_con = mlx_init();
	if (!data.mlx_con)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_con, WIDTH, HEIGHT, "Hello");
	if (!data.mlx_win)
		return (free(data.mlx_con), data.mlx_con = NULL, 1);
	//mlx_put_image_to_window(mlx_connection, mlx_window, 400, 300, 0xFF0000); // put a red pixel on center of window
	//Register key release hook
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, keypress, &data);
	// Register destroy hook
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &destroy_win, &data);
	// loop over the MLX pointer
	mlx_loop(data.mlx_con);
	return (0);
}
