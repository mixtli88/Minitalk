# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:34:23 by mabril            #+#    #+#              #
#    Updated: 2024/11/05 09:46:44 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BINDIR = bin
SRCDIR = src
LIBFT_DIR = lib/libft

HEADERS = inc/push_swap.h

SRC_S = $(addprefix $(SRCDIR)/, server.c)
SRC_C = $(addprefix $(SRCDIR)/, client.c )
OBJ_S = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRC_S))
OBJ_C = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRC_C))

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨$(CYAN) Compiled $@ $(DEFAULT)"

all: libft $(NAME_CLIENT) $(NAME_SERVER)

libft:
	@make -C $(LIBFT_DIR)
	
client: $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $@ -L$(LIBFT_DIR) -lft
	@echo "✅${GREEN} ${NAME_CLIENT} successfully created. 🌐${RESET}"

server: $(OBJ_S)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $@ -L$(LIBFT_DIR) -lft
	@echo "✅${GREEN} ${NAME_SERVER} Server successfully created. 🌐${RESET}\n"

clean:
	@rm -rf $(BINDIR)
	@echo "\n🧹 ${YELLOW} Binary files successfully removed 🗑${RESET}"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean -C $(LIBFT_DIR)
	@echo "🧹  ${RED} Executables successfully removed 🗑${RESET}\n"

re: fclean all

debug:
	@echo "SRC_S: $(SRC_S)"
	@echo "SRC_C: $(SRC_C)"
	@echo "OBJ_S: $(OBJ_S)"
	@echo "OBJ_C: $(OBJ_C)"
	@echo "Current directory: $(shell pwd)\n"

.PHONY: all clean fclean re libft debug
