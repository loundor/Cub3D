NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra ${F_EXTRA}
F_EXTRA		=	-g -fsanitize=address
LIBRARY		=	./libft/libft.a ./MLX42/libmlx42.a  ${LIB_LINUX}
LIB_LINUX	=	-ldl -lglfw -pthread -lm #${LIB_MAC}
LIB_MAC		=	-L "/Users/${USER}/.brew/opt/glfw/lib/"
INCLUDE		=	-I./include -I./libft -I./MLX42/include
SFOLDER		=	./srcs/
SRCS		=	main.c \
				error.c \
				$(addprefix map/, ${MAP}) \
				$(addprefix hook/, ${HOOK}) \
				$(addprefix free/, ${FREE}) \
				$(addprefix utils/, ${UTILS})
HOOK		=	hook.c
MAP			=	map.c \
				import_param.c \
				import_map.c
FREE		=	free_map.c \
				free_utils.c
UTILS		=	ft_get_struct.c \
				ft_file_exist.c
OBJS		=	$(addprefix ${SFOLDER}, ${SRCS: .c=.o})
RM			=	rm -rf

$(NAME)		:	${OBJS}
				@echo Linking 🔗
				@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -o $@
				@echo Making ⚒
				@echo "\033[0;32m-= Ready to play! 👾 =- \033[0;0m"

all			:	${NAME}

#re			:	fclean all

clean		:
				${RM} ${OBJS}

#fclean		:	clean
#				${RED} ${RM} ${NAME} ${RST}	

.PHONY		:	${NAME} all clean fclean re
