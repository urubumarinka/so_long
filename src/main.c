/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:22:28 by maborges          #+#    #+#             */
/*   Updated: 2025/05/12 16:17:42 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	void	*mlx_connetion;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Hello World");
	if (mlx_window == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection); // prt:
		return (MALLOC_ERROR);
	}
mlx_put_image_to_window(mlx_conection, mlx_window, 400, 300, 0xFF0000); // put a red pixel on center of window
	mlx_loop(mlx_connection);

	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	mlx_connetion = NULL; // should I here also free the pointer form inside minilibx struct?
}
