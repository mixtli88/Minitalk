# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:49:43 by mabril            #+#    #+#              #
#    Updated: 2024/04/29 18:28:45 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
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

$(NAME) :	$(OBJS)
	ar crs $(NAME) $(OBJS)

all :	$(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

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



