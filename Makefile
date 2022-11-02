NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra ${F_EXTRA}
F_EXTRA		=	-g -fsanitize=address
LIBRARY		=	./libft/libft.a ./MLX42/libmlx42.a ${LIB_LINUX}
LIB_LINUX	=	-ldl -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/" -pthread -lm ${LIB_MAC}
LIB_MAC		=	-L "/Users/${USER}/.brew/opt/glfw/lib/"
INCLUDE		=	-I./include -I./libft -I./MLX42/include
SFOLDER		=	./srcs/
SRCS		=	main.c \
				$(addprefix map/, ${MAP}) \
				$(addprefix free/, ${FREE}) \
				$(addprefix set/, ${SET}) \
				$(addprefix utils/, ${UTILS})
MAP			=	map.c \
				import_param.c \
				import_map.c \
				texture_param.c
FREE		=	free_base.c \
				free_map.c \
				free_obj.c \
				free_utils.c \
				free_window.c
SET			=	player.c \
				enemy.c \
				ammo.c \
				items.c \
				guns.c \
				map.c \
				window.c
UTILS		=	ft_get_struct.c \
				ft_test_file_if_exist.c
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
