NAME = libft.a

SRCS = ft_atoi.c ft_itoa_base_u.c ft_strdup.c ft_strlen.c ft_strnew.c ft_pow.c \
                   ft_memalloc.c ft_numlen.c ft_bzero.c ft_strjoin.c \
				   ft_strchr.c ft_strcpy.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
