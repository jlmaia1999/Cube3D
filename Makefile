NAME = cub3D

SRC_DIR = Source
PARSE_DIR = $(SRC_DIR)/Parsing
MINILIBX_DIR = Resources/Minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = Resources/Libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = Resources//ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = $(PARSE_DIR)/main.c \
		$(PARSE_DIR)/map_parsing.c \
		$(PARSE_DIR)/parsing_error.c\
		$(PARSE_DIR)/map_reader.c\
		$(PARSE_DIR)/map_extractor.c\
		$(PARSE_DIR)/txs_extractor.c\
		$(PARSE_DIR)/txs_parsing.c\



OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11

all: $(MINILIBX) $(LIBFT) $(PRINTF) $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf $(MLX_FLAGS) -o $(NAME)

download_minilibx:
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)

clean_minilibx:
	$(RM) -r $(MINILIBX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all clean mlx_download clean_minilibx