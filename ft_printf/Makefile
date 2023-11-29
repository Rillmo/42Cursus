SRCS = ft_printf.c ft_printer.c ft_hex.c ft_util.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = libft.a

%.o : %.c
	@$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@echo "[ compling ft_printf... ]"
	@ar -cr $(NAME) $(NAME) $(OBJS)
	@echo "[ OK ]"

$(LIBFT) :
	@make -s -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

clean :
	@echo "[ cleaning ft_printf... ]"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean :
	@echo "[ fcleaning ft_printf... ]"
	@rm -f $(OBJS) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY: clean fclean re