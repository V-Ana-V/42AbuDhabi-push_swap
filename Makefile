NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = parse1.c parse2.c check_err.c create_stack_a.c push_swap_cmnds.c \
rotate.c set_nodes_params_a.c set_nodes_params_b.c utils1.c utils2.c \
sort_3nodes.c sort.c push_swap_main.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re