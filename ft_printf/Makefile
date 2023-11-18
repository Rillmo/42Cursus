SRCS = ft_printf.c ft_printer.c ft_hex.c ft_util.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = libft.a

%.o : %.c
	$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	ar -cr $(NAME) $(NAME) $(OBJS)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

clean :
	rm -f $(LIBFT_DIR)/*.o
	rm -f *.o

fclean :
	rm -f $(LIBFT_DIR)/*.o $(LIBFT_DIR)/$(LIBFT)
	rm -f *.o $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re