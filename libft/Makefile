# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fpolycar <fpolycar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/15 10:52:08 by fpolycar      #+#    #+#                  #
#    Updated: 2022/01/09 12:48:51 by alfred        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar ru
INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS_LIST = libft.h get_next_line.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
SOURCES_DIRECTORY = ./sources/
c-files = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c  ft_strnstr.c ft_memchr.c \
			ft_atoi.c  ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c get_next_line.c get_next_line_utils.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(c-files))

c-bonus = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c
OBJECTS_DIRECTORY = objects/
o-files = $(patsubst %.c, %.o, $(c-files))
o-bonus = $(patsubst %.c, %.o, $(c-bonus))

ifdef WITH_BONUS
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(o-files) $(o-bonus))
else
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(o-files))
endif

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<


clean:
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: 
	$(MAKE) WITH_BONUS=1
