NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= push_swap.c add_stack_to.c create_stack.c duplicate_num.c \
				free_stack.c ft_atol.c push.c rotate.c reverse_rotate.c swap.c \
				parsing.c sort.c cost.c cost1.c push_to.c

OBJS		= $(SRCS:.c=.o)


CHECKER_NAME = checker

CHECKER_SRCS = checker.c \
				add_stack_to.c \
				create_stack.c \
				duplicate_num.c \
				free_stack.c \
				ft_atol.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				swap.c parsing.c sort.c \
				get_next_line.c get_next_line_utils.c

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER_NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME) $(CHECKER_OBJS)
	$(RM) $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re