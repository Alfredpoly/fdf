# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alfred <alfred@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/09 10:39:07 by alfred        #+#    #+#                  #
#    Updated: 2022/01/09 13:04:08 by alfred        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBRARIES = -L$(MLX_DIRECTORY) -L$(LIBFT_DIRECTORY) -lmlx -lft -lm -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MLX_DIRECTORY = ./mlx/
MLX_HEADERS = $(MLX_DIRECTORY)

HEADERS_LIST = fdf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
c-files = main.c init.c map.c translation.c draw_line.c hook.c utils.c project.c keyboard.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(c-files))

OBJECTS_DIRECTORY = ./objects/
o-files = $(patsubst %.c, %.o, $(c-files))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(o-files))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) -o $@ $<
	
$(LIBFT):
	@make bonus -C $(LIBFT_DIRECTORY)
	
clean:
	@make clean -C $(LIBFT_DIRECTORY)
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@make fclean -C $(LIBFT_DIRECTORY)
	@rm -f $(NAME)

re: fclean all

