SRCS =	sources/main.c \
		sources/map.c \
		sources/move.c \
		sources/image.c \
		sources/render.c

OBJS =	$(patsubst sources%, objects%, $(SRCS:.c=.o))

CC =	cc -Wall -Wextra -Werror
NAME =	so_long

INC =	-I./includes
LIB =	-L./libft -lft -L./mlx -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT =	libft/libft.a
GNL_SRCS = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
GNL_OBJS =	$(GNL_SRCS:.c=.o)

all : $(LIBFT) objects $(NAME)

$(LIBFT) :
	@echo " [ comipling libft... ] "
	@make -s -C libft
	@echo " [ libft ready ] "

objects :
	@mkdir -p objects

$(NAME) : $(GNL_OBJS) $(OBJS)	# objects/%.o
	@$(CC) $^ $(LIB) $(FRAMEWORK) -o $@
	@echo " [ so_long ready ] "

objects/%.o : sources/%.c
	@echo " [ comipling so_long... ]"
	@$(CC) -c $^ -o $@ $(INC)

get_next_line/%.o : get_next_line/%.c
	@echo " [ comipling gnl... ]"
	@$(CC) -c $^ -o $@

clean :
	@echo " [ cleaning so_long... ]"
	@make clean -C libft
	@rm -f $(GNL_OBJS)
	@rm -f $(OBJS)
	@echo " [ so_long cleaned ] "

fclean :
	@echo " [ fcleaning so_long... ]"
	@make fclean -C libft
	@rm -f $(GNL_OBJS)
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo " [ so_long fcleaned ] "

re :
	make fclean
	make all

.PHONY: clean fclean re
