SRCS = 	main.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror -g
NAME = pipex
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf

LIB = -L./ft_printf -lftprintf
INC = -I pipex.h

%.o : %.c
	@$(CC) -c $^ -o $@

all : $(PRINTF) $(NAME)

$(PRINTF) :
	@make -C $(PRINTF_DIR)

$(NAME) : $(OBJS)
	@echo "[ compling push_swap... ]"
	@$(CC) $^ $(LIB) $(INC) -o $@
	@echo "[ OK ]"


clean :
	@make clean -C $(PRINTF_DIR)
	@rm -f $(OBJS)
	@echo "[ cleaned push_swap ]"

fclean :
	@make fclean -C $(PRINTF_DIR)
	@rm -f $(OBJS) $(NAME)
	@echo "[ fcleaned push_swap ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re