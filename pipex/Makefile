SRCS = 	sources/main.c \
		sources/error.c \
		sources/process.c \
		sources/split.c \
		sources/parse.c \
		sources/util.c

SRCS_BONUS =	sources_bonus/main_bonus.c \
				sources_bonus/error_bonus.c \
				sources_bonus/process_bonus.c \
				sources_bonus/parse_bonus.c \
				sources_bonus/split_bonus.c \
				sources_bonus/heredoc_bonus.c \
				sources_bonus/util_bonus.c

OBJS = $(patsubst sources%, objects%, $(SRCS:.c=.o))
OBJS_BONUS = $(patsubst sources_bonus%, objects_bonus%, $(SRCS_BONUS:.c=.o))

CC = cc -Wall -Wextra -Werror -g
NAME = pipex
MANDATORY = .mandatory
BONUS = .bonus

PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf

GNL_SRCS =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIB = -L./ft_printf -lftprintf
INC = ./includes/pipex.h
INC_BONUS = ./includes/pipex_bonus.h

all : $(PRINTF) objects $(MANDATORY)

bonus : $(PRINTF) objects_bonus $(BONUS)

objects :
	@mkdir -p objects

objects_bonus :
	@mkdir -p objects_bonus

$(PRINTF) :
	@make -C $(PRINTF_DIR)

$(MANDATORY) : $(OBJS) $(INC)
	@echo "[ compling pipex... ]"
	@$(CC) $(OBJS) $(LIB) -I $(INC) -o $@
	@rm -f $(BONUS)
	@touch $@
	@cp $@ $(NAME)
	@echo "[ OK ]"

$(BONUS) : $(GNL_OBJS) $(OBJS_BONUS) $(INC_BONUS)
	@echo "[ compling pipex_bonus... ]"
	@$(CC) $(GNL_OBJS) $(OBJS_BONUS) $(LIB) -I $(INC_BONUS) -o $(BONUS)
	@rm -f $(MANDATORY)
	@touch $@
	@cp $@ $(NAME)
	@echo "[ OK ]"

objects/%.o : sources/%.c
	@$(CC) -c $^ -o $@

objects_bonus/%.o : sources_bonus/%.c
	@$(CC) -c $^ -o $@

get_next_line/%.o : get_next_line/%.c
	@echo "[ compling gnl... ]"
	@$(CC) -c $^ -o $@

clean :
	@make clean -C $(PRINTF_DIR)
	@rm -f $(OBJS) $(OBJS_BONUS) $(GNL_OBJS)
	@echo "[ cleaned pipex ]"

fclean :
	@make fclean -C $(PRINTF_DIR)
	@rm -f $(OBJS) $(OBJS_BONUS) $(GNL_OBJS) $(MANDATORY) $(BONUS) $(NAME)
	@echo "[ fcleaned pipex ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re