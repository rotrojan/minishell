NAME= 	libgc.a

GC= 	gc_exit.c			get_garbage_lst.c		gc_malloc.c			\
		gc_free.c			gc_free_all.c			gc_utils.c


SRCS=	$(GC)
OBJS= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR= .objs
DEPENDENCIES= $(OBJS:%.o=%.d)

CC= clang
MKDIR= mkdir -p
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -MMD
CXXFLAGS= -I includes

vpath %.c sources 

.SILENT:
all: $(NAME)

$(NAME): display $(OBJS)
	printf '\narchiving libgc\n'
	ar -rcs $(NAME) $(OBJS)
	printf '\033[33m\033[1mlibgc compiled\n\033[0m'

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	printf '\r\033[Kcompiling%s' '$@'
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

display:
	printf '\033[1mcompiling libgc\033[22m'

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	printf 'libgc removed\n'

re: fclean all

.PHONY: all clean fclean re display
