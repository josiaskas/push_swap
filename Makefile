NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = main.c parse_args.c heap_sort.c print_stacks.c \
	swap_op.c rotate_op.c reverse_rotate_op.c\
	partitions_op.c partitions_op_2.c push_back.c\
	particular_sort.c sort5.c\

SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objsm
OBJS = $(SRCS_PREFIXED:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) re -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@echo $(NAME) est construit

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)
	@echo cleaning

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	@echo "full clean"

re : fclean all

test3:all
	ruby -e "puts (1..3).to_a.shuffle.join(' ')" | xargs ./push_swap | wc -l
test5:all
	ruby -e "puts (1..5).to_a.shuffle.join(' ')" | xargs ./push_swap | wc -l
test100:all
	ruby -e "puts (1..100).to_a.shuffle.join(' ')" | xargs ./push_swap | wc -l
test400:all
	ruby -e "puts (1..400).to_a.shuffle.join(' ')" | xargs ./push_swap | wc -l
test500:all
	ruby -e "puts (1..500).to_a.shuffle.join(' ')" | xargs ./push_swap | wc -l
help	:
	@echo "all $(NAME) clean fclean re \033[0;32m test5 test3 test100 test400 test500 help\033[0;39m"

.PHONY	: all clean fclean re help
