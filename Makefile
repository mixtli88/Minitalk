# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:34:23 by mabril            #+#    #+#              #
#    Updated: 2024/11/04 19:54:10 by mabril           ###   ########.fr        #
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

SRCS = $(addprefix $(SRCDIR)/, client.c server.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))

# Headers
HEADERS = inc/push_swap.h

# Ensure libft is compiled first
all: libft $(NAME_CLIENT) $(NAME_SERVER)

libft:
	@make -C $(LIBFT_DIR)

# Rule for creating .o files in the bin directory
$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨$(CYAN) Compiled $@ $(DEFAULT)"

# Link client and server executables
$(NAME_CLIENT): $(OBJS)
	@$(CC) $(CFLAGS) $(BINDIR)/client.o -o $@ -L$(LIBFT_DIR) -lft
	@echo "✅${GREEN} ${NAME_CLIENT} successfully created. 🌐${DEFAULT}"

$(NAME_SERVER): $(OBJS)
	@$(CC) $(CFLAGS) $(BINDIR)/server.o -o $@ -L$(LIBFT_DIR) -lft
	@echo "✅${GREEN} ${NAME_SERVER} Server successfully created. 🌐${DEFAULT}"

clean:
	@rm -rf $(BINDIR)
	@echo "🧹 ${YELLOW} Binary files successfully removed 🗑${DEFAULT}"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean -C $(LIBFT_DIR)
	@echo "🗑️  ${RED} Executables successfully removed 🗑${DEFAULT}"

re: fclean all

# Debug rule to print variable values
debug:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "Current directory: $(shell pwd)"
	@ls -la $(SRCDIR)

.PHONY: all clean fclean re libft debug
