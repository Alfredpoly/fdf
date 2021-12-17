# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fpolycar <fpolycar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/15 10:52:08 by fpolycar      #+#    #+#                  #
#    Updated: 2021/12/15 10:52:09 by fpolycar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar ru
RM = rm -f

c-files = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c  ft_strnstr.c ft_memchr.c \
			ft_atoi.c  ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c 

c-bonus = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c

o-bonus = $(c-bonus:.c=.o)
o-files = $(c-files:.c=.o)

ifdef WITH_BONUS
OBJ_FILES = $(o-files) $(o-bonus)
else
OBJ_FILES = $(o-files)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<


clean:
	rm -f $(o-files) $(o-bonus)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: 
	$(MAKE) WITH_BONUS=1
