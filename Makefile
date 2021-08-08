NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = test.c

SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objsm
OBJS = $(SRCS_PREFIXED:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) re -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft  -o $(NAME)

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
