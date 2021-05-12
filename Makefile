# **************************************************************************** #
#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:53:41 by rotrojan          #+#    #+#              #
#    Updated: 2021/05/02 17:14:15 by lucocozz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
NAME = minishell

SRCS =	main.c 				shell.c 				prompt.c 				\
		ft_gethostname.c 	getbinpath.c 			signals.c				\
		tokens.c			ft_getpid.c				input.c					\
		exit_shell.c		getterm.c				init_term.c				\
		pipe_exec.c			shell_env.c				get_cursor_pos.c		\
		ft_getch.c			getos.c					keys.c
SRCS_DIR = sources
OBJS_DIR = .objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)
INCLUDES_DIR = includes $(LIBS:%=lib%/includes)
LIBS = gc ft
CC = clang
RM = rm -f
MKDIR = mkdir -p

CFLAGS = -MMD -Wall -Wextra -Werror

CXXFLAGS = $(INCLUDES_DIR:%=-I %)
LDFLAGS = $(LIBS:%=-L lib%) $(LIBS:%=-l%) -lncurses

vpath %.c	$(SRCS_DIR)	$(SRCS_DIR)/system	$(SRCS_DIR)/lexing				\
			$(SRCS_DIR)/shell	$(SRCS_DIR)/terminal
vpath %.h	$(INCLUDES_DIR)
vpath %.a	$(LIBS:%=lib%)

all:
	$(foreach LIB, ${LIBS}, ${MAKE} -C lib${LIB} ;)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) | $(LIBS:%=lib%.a)
	$(CC) $(CXXFLAGS) $^ -o $(NAME) $(LDFLAGS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

clean:
	$(foreach LIB, $(LIBS), $(MAKE) $@ -C lib$(LIB);)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(foreach LIB, $(LIBS), lib$(LIB)/lib$(LIB).a)

re: fclean all

.PHONY: all clean fclean re
