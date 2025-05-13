/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:48:45 by maborges          #+#    #+#             */
/*   Updated: 2025/05/13 14:04:12 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

// DIsplay size definitions
#define WIDTH 800
#define HEIGHT 600
#define TILE 32

// Textures path definitions
# define PATH_CAT "../assets/cat.xpm"
# define PATH_CHICKEN "../assets/chicken.xpm"
# define PATH_FARMTILE "../assets/farmTile.xpm"
# define PATHGRASS "../assets/grass.xpm"
# define PATH_HOUSE "../assets/house.xpm"

#include <mlx.h> // include minilibX header
#include <stdlib.h> // include standard library header
#include <stdio.h>
#include <X11/X.h> // include X11 header for X11 events
#include <X11/keysym.h> // include X11 keysym header for key events

typedef struct s_data
{
	void		*mlx_con; // MLX pointer
	void		*mlx_win; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

#endif

