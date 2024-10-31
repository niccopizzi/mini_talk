CFLAGS = -Wall -Wextra -Werror 

NAME = minitalk

MY_LIB = libft.a
MY_SOURCES = client.c server.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

server: 
	@cc $(CFLAGS) server.c -o server $(MY_LIB)
	@echo "Server compiled."

client: 
	@cc $(CFLAGS) client.c -o client $(MY_LIB)
	@echo "Client compiled"

$(NAME): server client

%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."

clean:
	@$(RM) server client
	@echo "Server and client executables removed."

re: clean all

.PHONY: all server client clean re  

