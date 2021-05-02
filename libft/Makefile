NAME= 	libft.a

INT=	ft_atoll.c			ft_atoi.c			ft_atoui.c				\
		ft_itoa.c			ft_nbrlen.c			ft_ltoa_base.c			\
		ft_uitoa.c			ft_uitoa_base.c
MEM=	ft_calloc.c			ft_bzero.c
STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c				\
		ft_strncmp.c		ft_split.c			ft_free_arrays.c		\
		ft_strjoin.c		ft_strcat.c			ft_strcpy.c				\
		ft_strdup.c			ft_strchr.c			ft_isdigit.c			\
		ft_isspace.c		ft_strdel.c
FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		ft_printf.c			ft_fprintf.c								\
		gnl.c				ft_fputstr.c
PRINTF=	ft_vfprintf.c		ft_parsing.c		ft_type_d_i.c			\
		ft_type_p.c			ft_types_c_s.c		ft_types_u_per.c		\
		ft_types_x_xu.c		ft_vfprintf_utils.c
GARBAGE_COLLECTOR= 			ft_exit.c			get_garbage_lst.c		\
		w_alloc.c			w_free.c


SRCS=	$(INT) $(FILE) $(STR) $(MEM) $(PRINTF) $(GARBAGE_COLLECTOR)
OBJS= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR= .objs
DEPENDENCIES= $(OBJS:%.o=%.d)

CC= clang
MKDIR= mkdir -p
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -MMD
CXXFLAGS= -I includes

vpath %.c integer file file/ft_vfprintf string memory file garbage_collector 

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
