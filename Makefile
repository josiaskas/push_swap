NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = main.c parse_args.c heap_sort.c print_stacks.c \
	swap_op.c rotate_op.c reverse_rotate_op.c\
	partitions_by_mediane.c partitions_by_chunks.c partitions_by_chunks_b.c \
	push_back.c particular_sort.c sort5.c\

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

test3:all
	python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"` 
test5:all
	python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"` 
test100:all
	python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` 
test400:all
	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` 
test500:all
	python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` 
help	:
	@echo "all $(NAME) clean fclean re \033[0;32m test5 test3 test100 test400 test500 help\033[0;39m"

.PHONY	: all clean fclean re help
