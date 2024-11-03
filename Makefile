# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:34:23 by mabril            #+#    #+#              #
#    Updated: 2024/11/03 18:10:29 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = minitalk

# # Colors

# GREEN = \033[32m
# RED = \033[31m
# YELLOW = \033[33m
# BLUE = \033[34m
# MAGENTA = \033[35m
# CYAN = \033[36m
# WHITE = \033[37m
# RESET = \033[0m

# # Compilador y flags
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g

# # Directorios
# SRCDIR = src
# INCDIR = inc
# LIBFT_DIR = lib/libft

# # Archivos fuente y objetos
# SRCS = $(addprefix $(SRCDIR)/, main.c utils.c init.c)
# OBJS = $(SRCS:.c=.o)

# # Headers
# HEADERS = $(INCDIR)/push_swap.h

# # Reglas principales
# all: $(NAME)

# $(NAME): $(OBJS)
# 	@make -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
# 	@echo "✅${GREEN}${NAME} successfully created. 🌐${DEFAULT}"

# # Crear directorio bin y compilar objetos
# bin/%.o: src/%.c
# 	@mkdir -p bin
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "🔨 Compilando $<"

# # Limpiar
# clean:
# 	@rm -rf bin
# 	@make -C $(LIBFT_DIR) clean
# 	@echo "🧹 ${YELLOW}Binary files successfully removed 🗑${DEFAULT}"

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIBFT_DIR) fclean
# 	@echo "🗑️  ${RED}Executables successfully removed 🗑${DEFAULT}"

# re: fclean all







# NAME_CLIENT = client
# NAME_SERVER = server

# # Compilador y flags
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g

# # Directorios
# SRCDIR = src
# INCDIR = inc
# LIBFT_DIR = lib/libft

# # Archivos fuente
# SRCS_CLIENT = $(SRCDIR)/client.c
# SRCS_SERVER = $(SRCDIR)/server.c

# # Objetos
# OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
# OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# # Headers
# HEADERS = $(INCDIR)/minitalk.h

# # Reglas principales
# all: $(NAME_CLIENT) $(NAME_SERVER)

# # Compilar cliente
# $(NAME_CLIENT): $(OBJS_CLIENT)
# 	@make -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)
# 	@echo "✅ Cliente compilado exitosamente"

# # Compilar servidor
# $(NAME_SERVER): $(OBJS_SERVER)
# 	@make -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)
# 	@echo "✅ Servidor compilado exitosamente"

# # Regla para compilar los archivos objeto
# %.o: %.c $(HEADERS)
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "🔨 Compilando $<"

# # Limpiar
# clean:
# 	@rm -f $(SRCDIR)/*.o
# 	@make -C $(LIBFT_DIR) clean
# 	@echo "🧹 Objetos eliminados"

# fclean: clean
# 	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
# 	@make -C $(LIBFT_DIR) fclean
# 	@echo "🗑️  Todo limpio"

# re: fclean all

# .PHONY: all clean fclean re






NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BINDIR = bin
SRCDIR = src
LIBFT_DIR = lib/libft

SRCS = $(addprefix $(SRCDIR)/, client.c server.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o)


# Headers
HEADERS = inc/push_swap.h


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(BINDIR)/client.o
	@make -C lib/libft
	@$(CC) $(CFLAGS) $(BINDIR)/client.o -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(BINDIR)/server.o 
	@$(CC) $(CFLAGS) $(BINDIR)/server.o -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

$(BINDIR)/%.o: ${SRCDIR}/%.c $(HEADERS)
	@mkdir -p bin
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compilando $<"
	
clean:
	@rm -rf $(BINDIR)
	@echo "🧹 ${YELLOW}Binary files successfully removed 🗑${DEFAULT}"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean -C ${LIBFT_DIR}
	@echo "🗑️  ${RED}Executables successfully removed 🗑${DEFAULT}"

re: fclean all

.PHONY: all clean fclean re