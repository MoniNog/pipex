NAME = pipex
CC = gcc
CFLAGS =  -Wall -Wextra -Wno-unused-parameter

SRC = src/main.c src/utils.c

OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes -Ilib/libft/includes
LIBFT = lib/libft/libft.a
LIBS = -Llib/libft -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C lib/libft

clean:
	@make -C lib/libft clean --silent
	@rm -f $(OBJS)

fclean: clean
	@make -C lib/libft fclean --silent
	@rm -f $(NAME)

re: fclean all