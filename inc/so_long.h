/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:48:45 by maborges          #+#    #+#             */
/*   Updated: 2025/05/14 19:03:53 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

// DIsplay size definitions
#define WIDTH 800
#define HEIGHT 600
#define TILE 32

// Textures path definitions
# define PATH_CAT "assets/cat.xpm"
# define PATH_CHICKEN "assets/chicken.xpm"
# define PATH_FARMTILE "assets/farm_tile.xpm"
# define PATHGRASS "assets/grass.xpm"
# define PATH_HOUSE "assets/house.xpm"

#include <mlx.h> // include minilibX header
#include <stdlib.h> // include standard library header
#include <stdio.h> // remove later when linking ft_printf
#include <X11/X.h> // include X11 header for X11 events
#include <X11/keysym.h> // include X11 keysym header for key events
#include "../libft/libft.h"
//#include "../printf/inc/ft_printf.h" // still need to link on my makefile

typedef struct s_map
{
	char	**grid; // 2D array of map
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}	t_map;

typedef struct s_data
{
	void		*mlx_con; // MLX pointer
	void		*mlx_win; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;



// My Functions prototypes

// Images
void	load_img(t_data *data);

// Map parsing
int		load_map(char *file, t_map *map); // open the file
//int		read_map(int fd, t_map *map); // use get_next_line to read lines
//int		validate_map(t_map *map); // check rectangular shape, borders, allowed characters
void	free_map(t_map *map); // for cleanup
#endif

