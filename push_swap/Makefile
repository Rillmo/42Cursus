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
		sources/manual_sorting.c \
		sources/manual_sorting_5.c

SRCS_BONUS =	sources_bonus/main.c

OBJS = $(patsubst sources%, objects%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst sources%, objects%, $(SRCS_BONUS:.c=.o))

CC = cc -Wall -Wextra -Werror
# -fsanitize=address -g
NAME = push_swap
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf
BONUS = checker

LIB = -L./ft_printf -lftprintf
INC = -I push_swap.h

objects/%.o : sources/%.c
	@$(CC) -c $^ -o $@

objects_bonus/%.o : sources_bonus/%.c
	@$(CC) -c $^ -o $@

objects :
	mkdir -p objects

objects_bonus :
	mkdir -p objects_bonus

all : $(PRINTF) objects $(NAME)

bonus : $(PRINTF) objects_bonus $(BONUS)

$(BONUS) : $(OBJS_BONUS)
	@echo "[ compling push_swap_bonus... ]"
	@$(CC) $^ $(LIB) $(INC) -o $@
	@echo "[ OK ]"

$(PRINTF) :
	@make -C $(PRINTF_DIR)

$(NAME) : $(OBJS)
	@echo "[ compling push_swap... ]"
	@$(CC) $^ $(LIB) $(INC) -o $@
	@echo "[ OK ]"

clean :
	@make clean -C $(PRINTF_DIR)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "[ cleaned push_swap ]"

fclean : clean
	@make fclean -C $(PRINTF_DIR)
	@rm -f $(NAME) $(BONUS)
	@echo "[ fcleaned push_swap ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re