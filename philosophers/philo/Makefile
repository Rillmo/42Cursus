SRCS = 	main.c \
		ft_atoi.c \
		setting.c \
		thread.c \
		utils.c \
		utils2.c

OBJS =	$(addprefix objects/, $(SRCS:.c=.o))

CC = 	cc -Wall -Wextra -Werror -fsanitize=thread -g
NAME =	philo
INC =	philo.h

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOUR_END=\033[0m

objects/%.o : %.c
	@$(CC) -c $^ -o $@

all : objects $(NAME)

objects :
	@mkdir -p objects

$(NAME) : $(OBJS) $(INC)
	@echo "[ compling philo... ]"
	@$(CC) $(OBJS) -I $(INC) -o $@
	@echo "[ $(COLOR_GREEN)OK$(COLOUR_END) ]"

clean :
	@rm -rf $(OBJS) objects
	@echo "[ $(COLOR_BLUE)cleaned philo$(COLOUR_END) ]"

fclean : clean
	@rm -f $(NAME)
	@echo "[ $(COLOR_BLUE)fcleaned philo$(COLOUR_END) ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re