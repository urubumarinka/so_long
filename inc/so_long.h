/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:48:45 by maborges          #+#    #+#             */
/*   Updated: 2025/05/21 13:11:11 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 32

// Textures path definitions
# define PATH_CAT "assets/cat.xpm"
# define PATH_C "assets/chicken.xpm"
# define PATH_W "assets/farm_tile.xpm"
# define PATH_G "assets/grass.xpm"
# define PATH_H "assets/house.xpm"

# include <mlx.h> // include minilibX header
# include <stdlib.h> // include standard library header
# include <stdio.h> // remove later when linking ft_printf
# include <X11/X.h> // include X11 header for X11 events
# include <X11/keysym.h> // include X11 keysym header for key events
# include "../libft/libft.h"
//#include "../printf/inc/ft_printf.h" // still need to link on my makefile

typedef struct s_player
{
	int		x; // Player x position
	int		y; // Player y position
	int		moves;
	int		collected;
} t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_player	player;
	int			exits;
	int			total_collect;
}	t_map;

typedef struct s_img
{
	void	*img; // MLX image pointer
	int		width; // Image width
	int		height; // Image height
} t_img;


typedef struct s_data
{
	void		*ptr; // MLX pointer
	void		*win; // MLX window pointer
	t_img		grass;
	t_img		cat;
	t_img		wall;
	t_img		chicken;
	t_img		house; // MLX image pointers (on the stack)
	t_map		map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;


// My Functions prototypes
// Images
void	load_img(t_data *data);
void	draw_tile(t_data *data, int row, int col);

// Map parsing
int		load_map(char *file, t_map *map); // open the file
int	check_map_elements(t_map *map); // check for P, E, C
//int		read_map(int fd, t_map *map); // use get_next_line to read lines
//int		validate_map(t_map *map); // check rectangular shape, borders, allowed characters
int		validate_map_path(t_map *map);

//Free and error handling
void	error_handler(const char *message);
void	free_map(t_map *map);
int		destroy_win(t_data *data);
void	free_images(t_data *data);


//Game Logic
int	keypress(int keycode, t_data *data);


#endif

