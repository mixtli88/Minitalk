# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:49:43 by mabril            #+#    #+#              #
#    Updated: 2024/11/13 21:23:22 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

SRCS = 	ft_p_memo.c	\
		ft_printf.c \
		ft_putchar.c \
		ft_puthexaup.c \
		ft_puthexatit.c	\
		ft_putnrb.c	\
		ft_putstr.c	\
		ft_unsigne.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME) :	$(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "\n📚 ${MAGENTA}Librerie ft_printf successfully created. 🌐${RESET}"

all :	
	@$(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "🧹 ${YELLOW} Binary files librerie ft_printf successfully removed 🗑${RESET}"

fclean : clean 
	@$(RM) $(NAME)
	@echo "🧹  ${RED} Librerie ft_printf successfully removed 🗑${RESET}"

re : fclean all

# NAME = libftprintf.a

# RM = rm -f

# SRCS = 	ft_memo.c	\
# 		ft_printf.c \
# 		ft_putchar.c \
# 		ft_puthexaup.c \
# 		ft_puthexatit.c	\
# 		ft_putnrb.c	\
# 		ft_putstr.c	\
# 		ft_unsigne.c \

# OBJ = $(SRCS:.c=.o)

# all: $(NAME)

# %.o: %.c
# 	cc -Wall -Werror -Wextra -c $< -o $@ -I.

# $(NAME): $(OBJ)
# 	@$(RM) $@
# 	ar rcs $@ $(OBJ)

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all



