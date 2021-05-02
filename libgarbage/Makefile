# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by rotrojan          #+#    #+#              #
#    Updated: 2021/05/02 19:47:02 by lucocozz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### SOURCES ####################################

SRCS_DIR		=	./srcs/
SRCS 			=	ft_exit.c get_garbage_lst.c w_alloc.c w_free.c
OBJS			=	${SRCS:%.c=${OBJS_DIR}%.o}
DEPENDENCIES	=	${OBJS:.o=.d}
LIBFT			= ../libft/

################################ MISCELLANEOUS #################################

INCLUDES_DIR	=	./includes/ $(LIBFT)/includes/
OBJS_DIR		=	./.objs/

CFLAGS			+=	-Wall -Wextra -Werror -MMD
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%}

NAME			=	libgarbage.a

##################################### BIN ######################################

CC				=	clang
AR				=	ar rcs
MKDIR			=	mkdir -p

#################################### RULES #####################################

vpath %.c ${SRCS_DIR}

all		:	${NAME}

${NAME}	:	${OBJS}
	${AR} $@ $^

-include ${DEPENDENCIES}
${OBJS_DIR}%.o : %.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

clean	:
	${RM} -r ${OBJS_DIR}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

.PHONY	:			re			\
					all			\
					clean		\
					fclean
