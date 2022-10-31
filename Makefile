NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address
LIBRARY		=	./libft/libft.a
INCLUDE		=	-I./include -I./libft
SFOLDER		=	./srcs/
SRCS		=	main.c ft_free.c
OBJS		=	$(addprefix ${SFOLDER}, ${SRCS: .c=.o})
RM			=	rm -rf

$(NAME)		:	${OBJS}
				${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -o $@

all			:	${NAME}

#re			:	fclean all

clean		:
				${RM} ${OBJS}

#fclean		:	clean
#				${RED} ${RM} ${NAME} ${RST}	

.PHONY		:	${NAME} all clean fclean re
