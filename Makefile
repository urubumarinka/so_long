NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
ifeq ($(shell uname -s), Linux)
    MLXFLAGS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lz
else
    MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz
endif

REMOVE = rm -f

SRC_DIR = src/

SRCS = \
$(SRC_DIR)main.c \
$(SRC_DIR)map_parsing.c \
$(SRC_DIR)player_movement.c \
$(SRC_DIR)game_loop.c \
$(SRC_DIR)check_path.c \
$(SRC_DIR)clean_and_exit.c \
$(SRC_DIR)init_images.c \
$(SRC_DIR)put_img.c \
$(SRC_DIR)read_map.c

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation successfully done!!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	$(MAKE) -C $(MLX_DIR)
	@echo "$(CYAN)Linking so_long...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)so_long executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
