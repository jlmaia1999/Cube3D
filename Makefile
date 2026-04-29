NAME = cub3D

SRC_DIR = Source
PARSE_DIR = $(SRC_DIR)/Parsing
EXEC_DIR = $(SRC_DIR)/Exec
MINILIBX_DIR = Resources/Minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = Resources/Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(PARSE_DIR)/main.c \
		$(PARSE_DIR)/map_parsing.c \
		$(PARSE_DIR)/parsing_error.c\
		$(PARSE_DIR)/map_reader.c\
		$(PARSE_DIR)/map_extractor.c\
		$(PARSE_DIR)/txs_extractor.c\
		$(PARSE_DIR)/txs_parsing.c\
		$(SRC_DIR)/cub3d.c\
		$(EXEC_DIR)/draw.c\
		$(EXEC_DIR)/mini_map.c\
		$(EXEC_DIR)/mlx_init.c\
		$(EXEC_DIR)/movement.c\
		$(EXEC_DIR)/ray.c\
		$(EXEC_DIR)/textures.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11

all: $(MINILIBX) $(LIBFT)  $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -lm $(MLX_FLAGS) -o $(NAME)

download_minilibx:
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)

clean_minilibx:
	$(RM) -r $(MINILIBX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all clean mlx_download clean_minilibx