# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 18:08:28 by mabril            #+#    #+#              #
#    Updated: 2024/11/04 19:57:08 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

RM = rm -f
SRC = 	ft_atoi.c		\
		ft_isalnum.c	\
		ft_strrchr.c	\
		ft_strchr.c		\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_calloc.c		\
		ft_bzero.c		\
		ft_putendl_fd.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_putchar_fd.c	\
		ft_substr.c		\
		ft_strdup.c 	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_strtrim.c	\
		ft_itoa.c		\
		ft_strjoin.c	\
		ft_memset.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strncmp.c	\
		ft_split.c		\
		ft_strtolowel.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@cc -Wall -Werror -Wextra -c $< -o $@ -I.
	
$(NAME): $(OBJ)
	@$(RM) $@
	@ar rcs $@ $(OBJ)
	@echo "📚 ${MAGENTA}Librerie successfully created. 🌐${DEFAULT}"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all