# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alfred <alfred@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/09 10:39:07 by alfred        #+#    #+#                  #
#    Updated: 2022/01/12 16:05:04 by alfred        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBRARIES = -L$(MLX_DIRECTORY) -L$(LIBFT_DIRECTORY) Memd/libmemd.a -lm -lft  -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS) -I./Memd/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MLX_DIRECTORY = ./mlx/
MLX_HEADERS = $(MLX_DIRECTORY)

HEADERS_LIST = fdf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
c-files = main.c init.c map.c draw_line.c hook.c utils.c project.c keyboard.c colors.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(c-files))

OBJECTS_DIRECTORY = ./objects/
o-files = $(patsubst %.c, %.o, $(c-files))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(o-files))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) Memd/libmemd.a
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c -g $(INCLUDES) -o $@ $<
	
$(LIBFT):
	@make bonus -C $(LIBFT_DIRECTORY)
	
clean:
	@make clean -C $(LIBFT_DIRECTORY)
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@make fclean -C $(LIBFT_DIRECTORY)
	@rm -f $(NAME)

re: fclean all

