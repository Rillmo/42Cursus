SRCS = 	main.c \
		ft_atoi.c \
		setting.c

OBJS =	$(addprefix objects/, $(SRCS:.c=.o))

CC = 	cc -Wall -Wextra -Werror
NAME =	philo
INC =	philo.h

objects/%.o : %.c
	@$(CC) -c $^ -o $@

all : objects $(NAME)

objects :
	@mkdir -p objects

$(NAME) : $(OBJS) $(INC)
	@echo "[ compling philo... ]"
	@$(CC) $(OBJS) -I $(INC) -o $@
	@echo "[ OK ]"

clean :
	@rm -rf $(OBJS) objects
	@echo "[ cleaned philo ]"

fclean : clean
	@rm -f $(NAME)
	@echo "[ fcleaned philo ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re