HEADERS = minitalk.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

all: server client

server : server.o
	(cd libft ; make)
	cc -o server $< $(LIBFT)

client : client.o
	(cd libft ; make)
	cc -o client $< $(LIBFT)

libclean:
	(cd libft ; make clean)

libexclean:
	(cd libft ; make fclean)

clean: libclean
	rm -rf client.o server.o

fclean: clean libexclean
	rm -f server client

re: fclean all