# OPTION
CC=gcc
CFLAGS= -pthread
#CFLAGS= -Wall -Werror -Wextra -pthread
RM= rm -f

# SOURCE
D_LOGIC= ./srcs/
D_UTILS= ./utils/
D_HEADERS = ./includes/

NAME=philo
SRCS=	$(D_LOGIC)main.c \
		$(D_LOGIC)init.c \
		$(D_LOGIC)life.c \
		$(D_UTILS)utils_1.c


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