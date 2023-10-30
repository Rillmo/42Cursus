SRCS = ft_printf.c ft_printer.c ft_hex.c ft_util.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = libftprintf.a

%.o : %.c
	$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $^

clean :
	rm -f *.o

fclean :
	rm -f *.o $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re