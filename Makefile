# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:34:23 by mabril            #+#    #+#              #
#    Updated: 2024/11/20 09:53:54 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

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
LIB_PRINT = lib/ft_printf

HEADERS = inc/push_swap.h

SRC_S = $(addprefix $(SRCDIR)/, server.c)
SRC_C = $(addprefix $(SRCDIR)/, client.c)
SRC_U = $(addprefix $(SRCDIR)/, utils.c)
OBJ_S = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRC_S))
OBJ_C = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRC_C))
OBJ_U = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRC_U))

# ******************************  BONUS **************************

BINDIR_BONUS = bin_bonus
SRCDIR_BONUS = src_bonus

HEADERS_BONUS = inc/minital_bonus.h

SRC_BONUS_S = $(addprefix $(SRCDIR_BONUS)/, server_bonus.c)
SRC_BONUS_C = $(addprefix $(SRCDIR_BONUS)/, client_bonus.c)
SRC_BONUS_U = $(addprefix $(SRCDIR_BONUS)/, utils_bonus.c)
OBJ_BONUS_S = $(patsubst $(SRCDIR_BONUS)/%.c, $(BINDIR_BONUS)/%.o, $(SRC_BONUS_S))
OBJ_BONUS_C = $(patsubst $(SRCDIR_BONUS)/%.c, $(BINDIR_BONUS)/%.o, $(SRC_BONUS_C))
OBJ_BONUS_U = $(patsubst $(SRCDIR_BONUS)/%.c, $(BINDIR_BONUS)/%.o, $(SRC_BONUS_U))

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨$(CYAN) Compiled $@ $(DEFAULT)"
	
$(BINDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@mkdir -p $(BINDIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨$(CYAN) Compiled $@ $(DEFAULT)"

all: libft $(OBJ_U) $(NAME_CLIENT) $(NAME_SERVER)

libft: 
	@make -C $(LIBFT_DIR)
	@make -C $(LIB_PRINT)
	
client: $(OBJ_C) $(OBJ_U)
	@$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_C) -o $@ -L$(LIBFT_DIR) -lft -L$(LIB_PRINT) -lftprintf
	@echo "✅${GREEN} ${NAME_CLIENT} successfully created. 🌐${RESET}"

server: $(OBJ_S) $(OBJ_U)
	@$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_S) -o $@ -L$(LIBFT_DIR) -lft -L$(LIB_PRINT) -lftprintf
	@echo "✅${GREEN} ${NAME_SERVER} Server successfully created. 🌐${RESET}\n"



bonus : libft $(OBJ_BONUS_U) ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

${NAME_CLIENT_BONUS} : $(OBJ_BONUS_C)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_U) $(OBJ_BONUS_C) -o $@ -L$(LIBFT_DIR) -lft -L$(LIB_PRINT) -lftprintf
	@echo "✅${GREEN} ${NAME_CLIENT_BONUS} successfully created. 🌐${RESET}"

${NAME_SERVER_BONUS} : $(OBJ_BONUS_S)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_U) $(OBJ_BONUS_S) -o $@ -L$(LIBFT_DIR) -lft -L$(LIB_PRINT) -lftprintf
	@echo "✅${GREEN} ${NAME_SERVER_BONUS} Server successfully created. 🌐${RESET}\n"



clean:
	@rm -rf $(BINDIR) $(BINDIR_BONUS)
	@echo "\n🧹 ${YELLOW} Binary files successfully removed 🗑${RESET}"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}
	@make fclean -C $(LIBFT_DIR) 
	@make fclean -C $(LIB_PRINT)
	@echo "🧹  ${RED} Executables successfully removed 🗑${RESET}\n"

re: fclean all


debug:
	@echo "SRC_S: $(SRC_S)"
	@echo "SRC_C: $(SRC_C)"
	@echo "OBJ_S: $(OBJ_S)"
	@echo "OBJ_C: $(OBJ_C)"
	@echo "Current directory: $(shell pwd)\n"

.PHONY: all clean fclean re libft debug bonus
