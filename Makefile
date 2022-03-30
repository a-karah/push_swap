CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap
SRCS = main.c \
		handle_error.c \
		parser.c \
		args_checker.c \
		stack_utils_1.c \
		stack_utils_2.c \
		sort.c \
		print_utils.c \
		stack_a_oper.c \
		stack_b_oper.c \
		stack_oper.c \
		moves.c \
		a_to_b.c \
		b_to_a.c \
		clean_vars.c
OBJS = $(SRCS:.c=.o)
NAME_BONUS = checker
SRCS_BONUS = checker.c \
		handle_error.c \
		parser.c \
		args_checker.c \
		stack_utils_1.c \
		stack_utils_2.c \
		print_utils.c \
		stack_a_oper.c \
		stack_b_oper.c \
		stack_oper.c \
		clean_vars.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBS = -L$(LIBFT_DIR) -lft

all: $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(LIBFT_DIR)/$(LIBFT_NAME):
	make -sC $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
