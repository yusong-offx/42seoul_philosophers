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
SRCS=$(D_LOGIC)main.c \
	$(D_LOGIC)stock.c \
	$(D_UTILS)atoi.c \
	$(D_UTILS)safemalloc.c \
	$(D_UTILS)split.c 

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(D_HEADERS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(D_HEADERS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re