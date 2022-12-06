# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 01:05:52 by jfruscia          #+#    #+#              #
#    Updated: 2022/12/06 22:09:56 by hwichoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

# thread
# CFLAGS += -fsanitize=thread

# address
# CFLAGS += -fsanitize=address

AR = ar rcs

RM = rm -f

SRCS = main.c ft_atoi.c utils.c philosophers.c action.c check_exit.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o$@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
