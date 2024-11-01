# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:34:23 by mabril            #+#    #+#              #
#    Updated: 2024/11/01 14:32:25 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CopyNAME = Minitalk

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directorios
SRCDIR = src
INCDIR = inc
LIBFT_DIR = lib/libft

# Archivos fuente y objetos
SRCS = main.c utils.c error.c regles.c trie.c init.c \
       regles_a.c regles_b.c conditions.c utils_2.c
OBJS = $(SRCS:%.c=bin/%.o)

# Headers
HEADERS = $(INCDIR)/push_swap.h

# Reglas principales
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ $(NAME) compilado exitosamente"

# Crear directorio bin y compilar objetos
bin/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p bin
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compilando $<"

# Limpiar
clean:
	@rm -rf bin
	@make -C $(LIBFT_DIR) clean
	@echo "🧹 Objetos eliminados"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "🗑️  Todo limpio"

re: fclean all