# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 19:17:41 by yusong            #+#    #+#              #
#    Updated: 2022/04/14 19:25:26 by yusong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OPTION
CC= gcc
CFLAGS= -Wall -Werror -Wextra
RM= rm -f

NAME= philo
SRCS= main.c utils.c exit_free.c init.c

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re