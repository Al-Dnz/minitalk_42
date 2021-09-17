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
LIB = libft/libft.a
LIBFT = libft
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
	${CC} $(CFLAGS) -I$(LIBFT) $(LIB) -I$(INC) $(OBJ_DIR)/client.o -o $(CLIENT)
	@echo "\n------------------------------"
	@echo "| => $(CLIENT) well created ! <= |"
	@echo "------------------------------"

$(SERVER): $(OBJ) $(INC)
	${CC} $(CFLAGS) -I$(LIBFT) $(LIB) -I$(INC) $(OBJ_DIR)/server.o -o $(SERVER)
	@echo "\n------------------------------"
	@echo "| => $(SERVER) well created ! <= |"
	@echo "------------------------------\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(LIBFT) 
	${CC} $(CFLAGS) -D$(OS_NAME) -I$(INC) -I$(LIBFT) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj files deleted"
	
fclean:	clean
	@(make fclean -C $(LIBFT))
	@rm -rf $(SERVER)
	@echo "\n=> [$(SERVER)]: deleted <=\n"
	@rm -rf $(CLIENT)
	@echo "\n=> [$(CLIENT)]: deleted <=\n"

re: fclean all

.PHONY: all, clean, fclean, re