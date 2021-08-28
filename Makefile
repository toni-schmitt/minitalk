# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmittstudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 16:59:37 by tschmitt          #+#    #+#              #
#    Updated: 2021/08/28 17:15:49 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f

CLIENT_PATH = ./client/
SERVER_PATH = ./server/
LIBFT_PATH = ./libs/libft/

CLIENT_NAME = $(CLIENT_PATH)client
SERVER_NAME = $(SERVER_PATH)server
LIBFT_NAME = $(LIBFT_PATH)lib/libft.a

CLIENT_SRC = $(CLIENT_PATH)client.c
SERVER_SRC = $(SERVER_PATH)server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

INCLUDE_FLAGS = -I $(LIBFT_PATH)include/

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(CLIENT_NAME) $(SERVER_NAME)
	@echo $(G)Finished...$(X)

$(LIBFT_NAME):
	@echo $(Y)Compiling [$(LIBFT_NAME)]...$(X)
	@make -C $(LIBFT_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(LIBFT_NAME)]$(X)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(CLIENT_NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(CLIENT_OBJ) $(LIBFT_NAME) -o $(CLIENT_NAME)
	@echo $(G)Finished [$(CLIENT_NAME)]$(X)

$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(SERVER_NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(SERVER_OBJ) $(LIBFT_NAME) -o $(SERVER_NAME)
	@echo $(G)Finished [$(SERVER_NAME)]$(X)

%.o: %.c
	@echo $(Y)Compiling [$@]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	@echo $(R)Cleaning"  "[$(SERVER_OBJ)]...$(X)
	@echo $(R)Cleaning"  "[$(CLIENT_OBJ)]...$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@echo $(R)Cleaning"  "[$(SERVER_NAME)]...$(X)
	@echo $(R)Cleaning"  "[$(CLIENT_NAME)]...$(X)