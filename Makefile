NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra  -Imlx ${F_EXTRA}
F_EXTRA		=	-g -fsanitize=address
LIBRARY		=	./libft.a
LIB_LINUX	=	-ldl -lglfw -pthread -lm #${LIB_MAC}
LIB_MAC		=	-L "/Users/${USER}/.brew/opt/glfw/lib/"
INCLUDE		=	-I./include -I./libft
SFOLDER		=	./srcs/
SRCS		=	main.c \
				$(addprefix map/, ${MAP}) \
				$(addprefix free/, ${FREE}) \
				$(addprefix utils/, ${UTILS}) \
MAP			=	map.c \
				import_param.c \
				import_map.c \
FREE		=	free_map.c \
				free_utils.c \
UTILS		=	ft_get_struct.c \
				ft_test_file_if_exist.c \
OBJS		=	$(addprefix ${SFOLDER}, ${SRCS: .c=.o})
RM			=	rm -rf

$(NAME)		:	${OBJS}
				@echo Linking 🔗
				@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -lmlx -framework OpenGL -framework AppKit -o $@
				@echo Making ⚒
				@echo "\033[0;32m-= Ready to play! 👾 =- \033[0;0m"

all			:	${NAME}

#re			:	fclean all

clean		:
				${RM} ${OBJS}

#fclean		:	clean
#				${RED} ${RM} ${NAME} ${RST}	

.PHONY		:	${NAME} all clean fclean re
