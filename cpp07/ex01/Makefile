SRCS = 	 \
		main.cpp

OBJS =	$(addprefix objects/, $(SRCS:.cpp=.o))

CPPFLAG = c++ -Wall -Wextra -Werror -std=c++98
NAME =	ex01

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOUR_END=\033[0m

objects/%.o : %.cpp
	@$(CPPFLAG) -c $^ -o $@

all : objects $(NAME)

objects :
	@mkdir -p objects

$(NAME) : $(OBJS)
	@echo "[ compling... ]"
	@$(CPPFLAG) $(OBJS) -o $@
	@echo "[ $(COLOR_GREEN)OK$(COLOUR_END) ]"

clean :
	@rm -rf $(OBJS) objects
	@echo "[ $(COLOR_BLUE)cleaned$(COLOUR_END) ]"

fclean : clean
	@rm -f $(NAME)
	@echo "[ $(COLOR_BLUE)fcleaned$(COLOUR_END) ]"
	
re :
	make fclean
	make all

.PHONY: clean fclean re