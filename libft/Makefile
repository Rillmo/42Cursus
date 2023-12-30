SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	   ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	   ft_strncmp.c	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			 ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			 ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
NAME = libft.a

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m

%.o : %.c
	@$(CC) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "[ compling libft... ]"
	@ar -cr $(NAME) $^
	@echo "[ $(COLOR_GREEN)OK$(COLOR_END) ]"

bonus : $(NAME) $(BONUS_OBJS)
	@echo "[ compling libft bonus... ]"
	@ar -cr $(NAME) $(BONUS_OBJS)
	@echo "[ $(COLOR_GREEN)OK$(COLOR_END) ]"

clean :
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "[ $(COLOR_BLUE)cleaned libft$(COLOR_END) ]"

fclean :
	@rm -f $(OBJS) $(BONUS_OBJS) $(NAME)
	@echo "[ $(COLOR_BLUE)fcleaned libft$(COLOR_END) ]"

re :
	make fclean
	make all

.PHONY: clean fclean re bonus
