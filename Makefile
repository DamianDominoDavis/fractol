NAME = fractol

SRC_DIR = ./src/
SRC_FILES = main.c hooks.c util.c mandelbrot.c julia.c burningship.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

INC_DIR = ./includes/
INCLUDES =  -I $(INC_DIR) $(MLX_INC)

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I $(MLX)
MLX_LNK	= -L minilibx -l mlx -framework OpenGL -framework AppKit

all: obj $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	@if [[ ! -e $(MLX_LIB) ]]; then make -C $(MLX) &> /dev/null; fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(MLX) clean &> /dev/null
	@rm -rf $(NAME)

re: fclean all

do: 
	@make clean
	@make
	@make clean

.PHONY: all obj $(NAME) clean fclean re do
