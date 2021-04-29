NAME= 	libft.a

INT=	ft_atoll.c
STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c
FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		gnl.c

SRCS=	$(addprefix integer/, $(INT)) $(addprefix file/, $(FILE))		\
		$(addprefix string/, $(STR))
OBJS= $(SRCS:%.c=%.o)
DEPENDENCIES= $(SRCS:%.c=%.d)

CC= clang

CFLAGS= -Wall -Wextra -Werror -MMD
CXXFLAGS= -I includes

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

-include $(DEPENDENCIES)
%.o: %.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
