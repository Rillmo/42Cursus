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
		sources/manual_sorting_5.c \
		sources/base4.c

SRCS_BONUS =	sources_bonus/main_bonus.c \
				sources_bonus/parsing_bonus.c \
				sources_bonus/util_bonus.c \
				sources_bonus/exception_bonus.c \
				sources_bonus/setting_bonus.c \
				sources_bonus/stack_util1_bonus.c \
				sources_bonus/stack_util2_bonus.c \
				sources_bonus/stack_func1_bonus.c


OBJS = $(patsubst sources%, objects%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst sources%, objects%, $(SRCS_BONUS:.c=.o))

CC = cc -Wall -Wextra -Werror
NAME = push_swap
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf
BONUS = checker

GNL_SRCS =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIB = -L./ft_printf -lftprintf
INC = ./includes/push_swap.h
INC_BONUS = ./includes/checker.h

objects/%.o : sources/%.c
	@$(CC) -c $^ -o $@

objects_bonus/%.o : sources_bonus/%.c
	@$(CC) -c $^ -o $@

all : $(PRINTF) objects $(NAME)

bonus : $(PRINTF) objects_bonus $(BONUS)

objects :
	@mkdir -p objects

objects_bonus :
	@mkdir -p objects_bonus

$(BONUS) : $(GNL_OBJS) $(OBJS_BONUS) $(INC_BONUS)
	@echo "[ compling push_swap_bonus... ]"
	@$(CC) $(GNL_OBJS) $(OBJS_BONUS) $(LIB) -I $(INC) -o $@
	@echo "[ OK ]"

$(PRINTF) :
	@make -C $(PRINTF_DIR)

$(NAME) : $(OBJS) $(INC)
	@echo "[ compling push_swap... ]"
	@$(CC) $(OBJS) $(LIB) -I $(INC) -o $@
	@echo "[ OK ]"

clean :
	@make clean -C $(PRINTF_DIR)
	@rm -f $(OBJS) $(OBJS_BONUS) $(GNL_OBJS)
	@echo "[ cleaned push_swap ]"

fclean : clean
	@make fclean -C $(PRINTF_DIR)
	@rm -f $(NAME) $(BONUS)
	@echo "[ fcleaned push_swap ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re