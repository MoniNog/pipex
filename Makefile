NAME = pipex
CC = gcc
CFLAGS =  -Wall -Wextra -Wno-unused-parameter

SRC = src/main.c

OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@make -C clean --silent
	@rm -f $(OBJS)

fclean: clean
	@make -C fclean --silent
	@rm -f $(NAME)

re: fclean all