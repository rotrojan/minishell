NAME= 	libft.a

INT=	ft_atoll.c

STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c

FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		gnl.c


SRCS=	$(addprefix integer/, $(INT)) $(addprefix file/, $(FILE))		\
		$(addprefix string/, $(STR))

OBJS_S= $(SRCS:%.c=%.o)

CC= clang

CFLAGS= -Wall -Wextra -Werror -I ./includes

all: $(NAME)

$(NAME): $(OBJS_S)
	ar -rcs $(NAME) $(OBJS_S)

clean:
	rm -f $(OBJS_S)

fclean: clean
	rm -f $(NAME)

re: fclean all
