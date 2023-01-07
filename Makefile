NAME		=	cub3D
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
				$(addprefix ray/, ${RAY}) \
				$(addprefix utils/, ${UTILS})
HOOK		=	hook.c
MAP			=	map.c \
				import_param.c \
				import_map.c
FREE		=	free_map.c \
				free_utils.c
UTILS		=	ft_get_struct.c \
				ft_file_exist.c \
				ft_file_name.c \
				ft_max.c
RAY			=	ft_sum_ray.c \
				ft_draw.c
OBJS		=	$(addprefix ${SFOLDER}, ${SRCS:.c=.o})
RM			=	rm -rf

.c.o	:
			@$(CC) $(FLAGS) -c $(HEADER) -g -fsanitize=address $< $ -o ${<:.c=.o}

$(NAME)		:	$(LIBFT) $(MLXGL) $(OBJS)
				@echo Linking 🔗
				@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -o $@
				@echo Making ⚒
				@echo "\033[0;32m-= Ready to play! 👾 =- \033[0;0m"

$(LIBFT) 	:
				@echo "Make of libft...🔥"
				@make -s -C ./libft

$(MLXGL)	:
				@echo "Make of minilibx 42 Codam...🔥"
				@make -s -C ./MLX42

all			:	$(NAME)

re			:	fclean all

clean		:
				@echo "Cleaning object... 🗑"
				@$(RM) $(OBJS)
				@echo "Cleaning libft...🗑"
				@make -s -C ./libft clean
				@echo "Cleaning MinilibX 42 Codam...🗑"
				@make -s -C ./MLX42 clean

fclean		:	clean
				@$(RM) $(NAME) $(LIBFT) $(MLXGL) 
				@make -C ./libft fclean
				@make -C ./MLX42 fclean
				@echo "Full clean finish... 🧹"

.PHONY		:	${NAME} all clean fclean re
