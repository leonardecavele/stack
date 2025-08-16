NAME = stack_machine

SRC_DIR = src
INC_DIR = include

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/parser.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all

debug:
	$(MAKE) CFLAGS="-fsanitize=undefined,leak -g3 $(CFLAGS)" re
