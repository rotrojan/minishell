NAME= 	libft.a

INT=	ft_atoll.c			ft_atoi.c			ft_atoui.c				\
		ft_itoa.c			ft_nbrlen.c			ft_ltoa_base.c			\
		ft_uitoa.c			ft_uitoa_base.c
MEM=	ft_realloc.c		ft_bzero.c			ft_memset.c				\
		ft_memcpy.c
STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c				\
		ft_strncmp.c		ft_split.c			ft_free_arrays.c		\
		ft_strjoin.c		ft_strcat.c			ft_strcpy.c				\
		ft_strdup.c			ft_strchr.c			ft_isdigit.c			\
		ft_isspace.c		ft_strdel.c			ft_iscntrl.c			\
		ft_putxchar.c		ft_isalnum.c		ft_strlcpy.c			\
		ft_strndup.c		ft_strnlen.c		ft_strstr.c				\
		ft_strncpy.c
FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		ft_printf.c			ft_dprintf.c		readfile.c				\
		gnl.c				ft_putstr_fd.c		ft_putchar_fd.c			\
		ft_putchar_err.c	ft_vdprintf.c
FORMAT= vformat.c			format.c			convert_percent.c		\
		convert_c.c			convert_s.c			convert_d.c				\
		convert_i.c			convert_x.c			convert_X.c
SYS=	debug.c
LIST=	ft_create_elem.c	ft_list_clear.c		ft_list_push_back.c		\
		ft_list_size.c		ft_list_to_array.c


SRCS=	$(INT) $(FILE) $(STR) $(MEM) $(SYS) $(LIST) $(FORMAT)
OBJS= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR= .objs
DEPENDENCIES= $(OBJS:%.o=%.d)
INCLUDES_DIR = includes $(LIBS:%=lib%/includes)
LIBS = gc

CC= clang
MKDIR= mkdir -p
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -MMD
CXXFLAGS= -I includes $(INCLUDES_DIR:%=-I ../%)

vpath %.c integer file string memory file system list string/format string/format/convert_types

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
