NAME=	minishell

SRCS=	main.c

SOURCES= $(addprefix sources/, $(SRCS))

CC=		clang

CFLAGS= -Wall -Wextra -Werror -I includes/ -I libft/includes/ -L libft/ -lft

all: lib $(NAME)

lib:
	$(MAKE) -C libft

$(NAME):
	$(CC) $(CFLAGS)

clean:
	$(MAKE) clean -C libft

fclean:
	$(MAKE) fclean -C libft

re: fclean all
