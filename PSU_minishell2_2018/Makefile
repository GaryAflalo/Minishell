##
## EPITECH PROJECT, 2019
## .
## File description:
## .
##


CC	= 	gcc

RM	= 	rm -f

CFLAGS	=  	-Wall -Iinclude/

NAME	= 	mysh

SRCS	= 	main.c \
		utils.c \
		init_listenv.c \
		my_str_to_wordtab.c \
		check_command.c \
		utils_env.c \
		my_exec.c \
		my_str.c \
		my_builtin.c \
		my_builtin_cd.c \
		my_getnbr.c \
		my_free.c \
		my_puterror.c

OBJS	=	$(addprefix src/, $(SRCS:.c=.o))

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

# -W -Wall -Werror -Wextra -pedantic
