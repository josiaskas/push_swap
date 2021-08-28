NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = test.c parse_args.c heap_sort.c print_stacks.c \
		swap_op.c rotate_op.c reverse_rotate_op.c\
		partitions.c big_sort.c\

SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objsm
OBJS = $(SRCS_PREFIXED:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) re -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@echo $(NAME) est fait

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

help	:
	@echo "all $(NAME) clean fclean re \033[0;32m help\033[0;39m"

.PHONY	: all clean fclean re help
