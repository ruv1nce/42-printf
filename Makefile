CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBDIR = ./libft/
SRC = ft_printf.c parser.c make_string.c printer.c
LIBFILES = ft_atoi.c ft_itoa_base_u.c ft_strdup.c ft_strlen.c ft_strnew.c \
		   ft_memalloc.c ft_numlen.c ft_bzero.c ft_strjoin.c
LIBSRC = $(patsubst %, $(LIBDIR)%, $(LIBFILES))
OBJ = $(SRC:.c=.o)
LIBOBJ = $(LIBSRC:.c=.o)
INC = ft_printf.h libft/libft.h

.PHONY: all clean fclean re lib

all: $(NAME)

$(NAME): lib
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

lib:
	$(MAKE) -C ./libft/

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft/ clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all
