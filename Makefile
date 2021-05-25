# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:51:42 by rotrojan          #+#    #+#              #
#    Updated: 2021/05/25 17:35:08 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c 				shell.c 				prompt.c 				\
		ft_gethostname.c	getbinpath.c 			signals.c				\
		inchar.c			ft_getpid.c				input.c					\
		exit_shell.c		getterm.c				init_term.c				\
		pipe_exec.c			env.c					get_cursor_pos.c		\
		ft_getch.c			arrow_keys.c			inchar_utils.c			\
		put_in_history.c	get_history.c			cursor_utils.c			\
		special_keys.c		history_utils.c			history_get_up.c		\
		history_get_down.c	ft_inenv.c				ft_setenv.c				\
		ft_unsetenv.c		ft_getenv.c				cd.c					\
		env.c				exit.c					pwd.c					\
		lexer.c				tok_alnum.c				tok_squote.c			\
		tok_dquote.c		tok_utils.c				tok_var.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

SRCS_DIR = sources
OBJS_DIR = .objs
INCLUDES_DIR = includes $(LIBS:%=lib%/includes)

LIBS = gc ft

MAKE = make
CC = clang
RM = rm -f
MKDIR = mkdir -p
DEBUG = off

CFLAGS = -MMD -Wall -Wextra #-Werror
CXXFLAGS = $(INCLUDES_DIR:%=-I %)
ifeq ($(DEBUG), on)
	CXXFLAGS += -g3 -fsanitize=address
endif
LDFLAGS = $(LIBS:%=-L lib%) $(LIBS:%=-l%) -lncurses

vpath %.c	$(addprefix $(SRCS_DIR), /. /terminal			\
				$(addprefix /system, /. /env)				\
				$(addprefix /lexing, /. /tokenizers)		\
				$(addprefix /shell, /. /history /inchar)	\
				/builtins)

all:
	$(foreach LIB, ${LIBS}, ${MAKE} -C lib${LIB} ;)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) | $(LIBS:%=lib%.a)
	$(CC) $(CXXFLAGS) $^ -o $(NAME) $(LDFLAGS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c $(OBJS_DIR)/debug$(DEBUG) | $(OBJS_DIR) 
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

$(OBJS_DIR)/debug$(DEBUG): | $(OBJS_DIR)
	$(RM) $(OBJS_DIR)/debug*
	touch $@

clean:
	$(foreach LIB, $(LIBS), $(MAKE) $@ -C lib$(LIB);)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(foreach LIB, $(LIBS), lib$(LIB)/lib$(LIB).a)

re: fclean all

.PHONY: all clean fclean re
