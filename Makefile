CC = gcc

CFLAGS = -Wall -Werror -Wextra

SEREXE = server

CLNEXE = client

NAME = $(SEREXE) $(CLNEXE)

NAME_BONUS = server_bonus client_bonus

FILES_SERVER = server.c 

FILES_CLIENT = client.c

SER_BONUS = server_bonus.c 

CNT_BONUS = client_bonus.c

all : $(NAME)

$(NAME) : $(FILES_CLIENT) $(FILES_SERVER)
	$(CC) $(CFLAGS)  $(FILES_SERVER) -o server
	$(CC) $(CFLAGS) $(FILES_CLIENT) -o client

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(CNT_BONUS) $(SER_BONUS)
	$(CC) $(CFLAGS)  $(SER_BONUS) -o server_bonus
	$(CC) $(CFLAGS) $(CNT_BONUS) -o client_bonus

clean :

	rm -f client server

fclean : clean

	rm -f client_bonus server_bonus

re : clean all

re_bonus : fclean bonus