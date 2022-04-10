# OPTION
CC=gcc
CFLAGS= 
# CFLAGS= -Wall -Werror -Wextra
RM= rm -f

# SOURCE
D_LOGIC= ./srcs/
D_UTILS= ./utils/
D_HEADERS = ./includes/

NAME=philo
SRCS=	$(D_LOGIC)main.c \
		$(D_LOGIC)init.c \
		$(D_LOGIC)life.c \
		$(D_UTILS)utils.c


OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -pthread -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re