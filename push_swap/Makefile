SRCS = push_swap.c util.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = push_swap
PRINTF_DIR = ft_printf
PRINTF = libftprintf.a

%.o : %.c
	$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(PRINTF) $(OBJS)
	cc -o $(NAME) $(NAME) $(OBJS)

$(PRINTF) :
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/$(PRINTF) $(NAME)

clean :
	make clean -C $(PRINTF_DIR)
	rm -f *.o

fclean :
	make fclean -C $(PRINTF_DIR)
	rm -f *.o $(NAME)
	
re :
	make fclean
	make all

.PHONY: clean fclean re