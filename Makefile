CC = gcc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f
FDF = fdf
LIBFT = ./libft/libft.a

c-files = main.c getnextline/get_next_line.c getnextline/get_next_line_utils.c init.c map.c translation.c draw_line.c hook.c

o-files = $(c-files:.c=.o)

OBJ = $(o-files)

all: $(LIBFT) $(FDF)

$(LIBFT):
	@make bonus -C libft

$(FDF): $(OBJ)
	$(CC) $(OBJ) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(FDF) $(LIBFT)

%.o: %.c
	$(CC) -Imlx -c -o $@ $<

clean:
	@make clean -C libft
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	rm -f $(FDF)

re: fclean all

