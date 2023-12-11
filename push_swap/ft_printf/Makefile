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
	@make bonus -s -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "[ cleaned ft_printf ]"

fclean :
	@rm -f $(OBJS) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "[ fcleaned ft_printf ]"

re :
	make fclean
	make all

.PHONY: clean fclean re