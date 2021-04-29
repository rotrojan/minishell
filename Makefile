# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:53:41 by rotrojan          #+#    #+#              #
#    Updated: 2021/04/29 17:47:55 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c
SRCS_DIR = srcs
OBJS = $(SRCS:%.s=%.o)
DEPENDENCIES = $(SRCS:%.s=%.d)
OBJS_DIR = .objs
INCLUDES_DIR = includes
LIBS = ft
CC = clang

CFLAGS = -Wall -Wextra -Werror -MMD

CXXFLAGS = -I includes/ -I libft/includes/ -L libft/ -lft

vpath %.c $(SRCS_DIR)
vpath %.h $(INCLUDES_DIR)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CXXFLAGS) $(OBJS) -o $@

-include DEPENDENCIES
%.o: %.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

lib%.a:
	$(MAKE) -C $(@:%.a:%)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS_DIR)

fclean:
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
