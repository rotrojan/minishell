# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:53:41 by rotrojan          #+#    #+#              #
#    Updated: 2021/04/29 18:30:18 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
NAME = minishell

SRCS = main.c
SRCS_DIR = sources
OBJS = $(SRCS:%.s=%.o)
DEPENDENCIES = $(SRCS:%.s=%.d)
OBJS_DIR = .objs
INCLUDES_DIR = includes $(LIBS:%=lib%)/includes -lncurses
LIBS = ft
CC = clang
RM = rm -f
MKDIR = mkdir -p

CFLAGS = -Wall -Wextra -Werror -MMD

CXXFLAGS = $(INCLUDES_DIR:%=-I%)
#LDFLAGS = -L

vpath %.c $(SRCS_DIR)
vpath %.h $(INCLUDES_DIR)
vpath %.a $(LIBS:%=lib%)

all:
	$(foreach LIB, ${LIBS}, ${MAKE} -C lib${LIB} &)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBS:%=lib%.a)
	$(CC) $(LDFLAGS) $(CXXFLAGS) $^ -o $@

-include DEPENDENCIES
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

clean:
	$(MAKE) clean -C libft
	$(RM) -r $(OBJS_DIR)

fclean:
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
