SRCS =	client.c \
		server.c \

CLIENT = client
SERVER = server

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
 OS_NAME = MAC_OS
else
 OS_NAME = LINUX
endif

CC = clang
LIB = ./libft/libft.a
LIBFT = ./libft
CFLAGS = -g3 -Wall -Wextra -Werror

INC	= inc
SRC_DIR = src
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:
	@(mkdir -p $(OBJ_DIR))
	@(make -C $(LIBFT))
	@(make -j $(CLIENT))
	@(make -j $(SERVER))

$(CLIENT): $(OBJ)
	${CC} $(CFLAGS) $(OBJ_DIR)/client.o  $(LIB) -I$(INC) -o $(CLIENT)
	@echo "\n------------------------------"
	@echo "| => $(CLIENT) well created ! <= |"
	@echo "------------------------------"

$(SERVER): $(OBJ) $(INC)
	${CC} $(CFLAGS)  $(OBJ_DIR)/server.o $(LIB) -I$(INC) -o $(SERVER)
	@echo "\n------------------------------"
	@echo "| => $(SERVER) well created ! <= |"
	@echo "------------------------------\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	${CC} $(CFLAGS) -D$(OS_NAME) -I$(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj files deleted"
	
fclean:	clean
	@(make fclean -C $(LIBFT))
	@rm -rf $(SERVER)
	@echo "\n=> [$(SERVER)]: deleted <=\n"
	@rm -rf $(CLIENT)
	@echo "\n=> [$(CLIENT)]: deleted <=\n"
	@rm -rf server_bonus client_bonus

re: fclean all

bonus: fclean
	@(make -C $(LIBFT))
	@rm -f -- server_bonus
	@rm -f -- client_bonus
	${CC} $(CFLAGS)  bonus/server.c $(LIB) -Ibonus/minitalk.h -o server_bonus
	${CC} $(CFLAGS)  bonus/client.c $(LIB) -Ibonus/minitalk.h -o client_bonus
	@rm -f *.dSYM
	@echo "\n------------------------------"
	@echo "| => bonus well created ! <= |"
	@echo "------------------------------\n"

.PHONY: all, clean, fclean, re