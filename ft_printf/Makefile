SRCS = ft_printf.c ft_printer.c ft_hex.c ft_util.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = libft.a

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m

%.o : %.c
	@$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@echo "[ compling ft_printf... ]"
	@ar -cr $(NAME) $(NAME) $(OBJS)
	@echo "[ $(COLOR_GREEN)OK$(COLOR_END) ]"

$(LIBFT) :
	@make -s -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "[ $(COLOR_BLUE)cleaned ft_printf$(COLOR_BLUE) ]"

fclean :
	@echo "[ fcleaned ft_printf ]"
	@rm -f $(OBJS) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY: clean fclean re