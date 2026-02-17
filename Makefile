NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC = \
	add_stack_to.c \
	create_stack.c \
	duplicate_num.c \
	free_stack \
	ft_atol.c \
	parsing.c \
	push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort.c \
	swap.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
