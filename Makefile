NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus 
INCLUDES = minitalk.h
INCLUDES_BONUS = minitalk_bonus.h
SERVER_SRC = server.c utils.c utils2.c
CLIENT_SRC = client.c utils.c utils2.c
SERVER_SRC_BONUS = server_bonus.c utils.c utils2.c
CLIENT_SRC_BONUS = client_bonus.c utils.c utils2.c
OBJ_CLIENT = $(CLIENT_SRC:.c=.o)
OBJ_SERVER = $(SERVER_SRC:.c=.o)
OBJ_CLIENT_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SERVER_SRC_BONUS:.c=.o)
REM = rm -rf

.PHONY: all clean fclean

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(INCLIDES) $(OBJ_SERVER) $(SERVER_SRC) Makefile
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) $(OBJ_SERVER) -o $(NAME_SERVER)
	@echo "SERVER IS READY"

$(NAME_CLIENT): $(INCLIDES) $(OBJ_CLIENT) $(CLIENT_SRC) Makefile
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) $(OBJ_CLIENT) -o $(NAME_CLIENT)
	@echo "CLIENT IS READY"

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(INCLIDES_BONUS) $(OBJ_SERVER_BONUS) $(SERVER_SRC_BONUS) Makefile
	@gcc -Wall -Wextra -Werror -I $(INCLUDES_BONUS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS)
	@echo "SERVER_BONUS IS READY"

$(NAME_CLIENT_BONUS): $(INCLIDES_BONUS) $(OBJ_CLIENT_BONUS) $(CLIENT_SRC_BONUS) Makefile
	@gcc -Wall -Wextra -Werror -I $(INCLUDES_BONUS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)
	@echo "CLIENT_BONUS IS READY"

.c.o:
	@gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

clean:
	$(REM) $(OBJ_CLIENT) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER) $(OBJ_SERVER_BONUS)

fclean:	clean
	$(REM) $(NAME_CLIENT) $(NAME_CLIENT_BONUS)  $(NAME_SERVER) $(NAME_SERVER_BONUS)

re:	fclean all
