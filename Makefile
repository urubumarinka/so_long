NAME = so_long

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


INCLUDES = -I/usr/include -Imlx

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

MLXFLAGS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lz

REMOVE = rm -f

SRC_DIR = src/

SRCS = \
$(SRC_DIR)main.c \
$(SRC_DIR)map_parsing.c \
$(SRC_DIR)map_parsing_utils.c \
$(SRC_DIR)game_loop.c \
$(SRC_DIR)load_img.c \
$(SRC_DIR)frees_and_errors.c \

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(MLX_LIB) $(NAME)
	@echo "$(GREEN)Compilation successfully done!!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	$(MAKE) -C $(MLX_DIR)
	@echo "$(CYAN)Linking so_long...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLXFLAGS)
	@echo "$(GREEN)so_long executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(MLX_LIB):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	$(MAKE) -C $(MLX_DIR)


clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	if [ -d "./mlx" ]; then make -C $(MLX_DIR) clean; fi

re: fclean all

.PHONY: all clean fclean re
