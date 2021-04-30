NAME= 	libft.a

INT=	ft_atoll.c
SYS=	ft_exit_error.c
MEM=	ft_calloc.c			ft_bzero.c
STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c				\
		ft_strncmp.c		ft_split.c			ft_free_arrays.c		\
		ft_strjoin.c		ft_strcat.c			ft_strcpy.c				\
		ft_strdup.c
FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		ft_printf.c			ft_fprintf.c
		gnl.c				ft_fputstr.c
PRINTF=	ft_vfprintf.c		ft_parsing.c		ft_type_d_i.c			\
		ft_type_p.c			ft_types_c_s.c		ft_types_u_per.c		\
		ft_types_x_xu.c		ft_vfprintf_utils.c

SRCS=	$(addprefix integer/, $(INT)) $(addprefix file/, $(FILE))		\
		$(addprefix string/, $(STR)) $(addprefix system/, $(SYS))		\
		$(addprefix memory/, $(MEM)) $(addprefix file/ft_vfprintf/, $(PRINTF))
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
