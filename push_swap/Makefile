SRCS = 	sources/main.c \
		sources/util.c \
		sources/stack_func1.c \
		sources/stack_func2.c \
		sources/stack_util1.c \
		sources/stack_util2.c \
		sources/sort.c \
		sources/setting.c \
		sources/parsing.c \
		sources/exception.c \
		sources/manual_sorting.c

SRCS_BONUS =	sources/bonus/main.c

OBJS = $(patsubst sources%, objects%, $(SRCS:.c=.o))

CC = cc -Wall -Wextra -Werror -fsanitize=address
NAME = push_swap
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf

LIB = -L./ft_printf -lftprintf
INC = -I push_swap.h

%.o : %.c
	@$(CC) -c $^ -o $@

objects :
	mkdir -p objects

all : $(PRINTF) objects $(NAME)

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