NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

PRINTF = libftprintf.a
CC = cc
RM = rm -f
CFLAGS =  -Wall -Wextra -Werror

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_SERVER): $(OBJ_SERVER)
	@make -C ft_printf
	$(CC) $(CFLAGS)  $(OBJ_SERVER) ft_printf/$(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) ft_printf/$(PRINTF) -o $(NAME_CLIENT) 


$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	@make -C ft_printf
	$(CC) $(CFLAGS)  $(OBJ_SERVER_BONUS) ft_printf/$(PRINTF) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) ft_printf/$(PRINTF) -o $(NAME_CLIENT_BONUS) 


clean:
	@make clean -C ft_printf
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	@make fclean -C ft_printf
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re
