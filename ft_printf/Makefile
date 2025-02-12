# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 17:31:56 by sngantch          #+#    #+#              #
#    Updated: 2025/01/04 16:43:07 by sngantch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC =  ar rcs
RM = rm -f 

SRCS = ft_print_numb_hex.c   ft_printf.c   ft_printf_int.c   \
		ft_putunsigned.c   	ft_print_ptr.c utils.c

OBJS =  $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
