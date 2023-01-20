NAME		=	cub3D
BONUS		=	$(NAME)
LIBFT		=	libft.a
MLXGL		=	libmlx42.a
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra ${F_EXTRA}
F_EXTRA		=	-g -fsanitize=address
LIBRARY		=	./libft/libft.a ./MLX42/libmlx42.a  -ldl -lglfw -pthread -lm ${LIB_MAC}
LIB_MAC		=	-L "/Users/${USER}/.brew/opt/glfw/lib/"
INCLUDE		=	-I./include -I./libft -I./MLX42/include
INCLUDEB	=	-I./bonus/include -I./libft -I./MLX42/include
SRCS		=	./srcs/main.c \
				./srcs/error.c \
				$(addprefix ./srcs/map/, ${MAP}) \
				$(addprefix ./srcs/hook/, ${HOOK}) \
				$(addprefix ./srcs/free/, ${FREE}) \
				$(addprefix ./srcs/ray/, ${RAY}) \
				$(addprefix ./srcs/utils/, ${UTILS})
HOOK		=	hook.c
MAP			=	map.c \
				import_param.c \
				import_map.c
FREE		=	free_map.c \
				free_utils.c \
				free_utils_2.c
UTILS		=	ft_get_struct.c \
				ft_file_exist.c \
				ft_file_name.c \
				ft_max.c
RAY			=	ft_sum_ray.c \
				ft_draw.c

BNS			=	./bonus/srcs/main.c \
				./srcs/error.c \
				$(addprefix ./bonus/srcs/map/, ${BMAP}) \
				$(addprefix ./bonus/srcs/hook/, ${BHOOK}) \
				$(addprefix ./srcs/free/, ${FREE}) \
				$(addprefix ./bonus/srcs/ray/, ${BRAY}) \
				$(addprefix ./bonus/srcs/utils/, ${BUTILS}) \
				$(addprefix ./bonus/srcs/texture/, ${TEXTURE}) \
				$(addprefix ./bonus/srcs/bonus/, ${ADDONS})
BHOOK		=	hook.c \
				mouse_hook.c
BMAP		=	map.c \
				import_param.c \
				import_map.c
BUTILS		=	ft_get_struct.c \
				ft_file_exist.c \
				ft_file_name.c \
				ft_max.c
BRAY		=	ft_sum_ray.c \
				ft_draw.c
TEXTURE		=	ft_atexture.c
ADDONS		=	ft_minimap.c \
				ft_door.c
OBJS		=	$(SRCS:%.c=%.o)
OBJSB		=	$(BNS:%.c=%.o)
RM			=	rm -rf

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(MLXGL) $(OBJS)
				@$(CC) $(FLAGS) $(OBJS) $(INCLUDES) $(LIBRARY) -o $(NAME)
				@echo "\033[0;32m-= Ready to play! 👾 =- \033[0;0m"

$(LIBFT) 	:
				@echo "Make of libft...🔥"
				@make -C ./libft

$(MLXGL)	:
				@echo "Make of minilibx 42 Codam...🔥"
				@make -C ./MLX42

re			:	fclean all

clean		:
				@echo "Cleaning object... 🗑"
				@$(RM) $(OBJS) $(OBJSB)
				@echo "Cleaning object libft...🗑"
				@make -s -C ./libft clean
				@echo "Cleaning object MinilibX 42 Codam...🗑"
				@make -s -C ./MLX42 clean

fclean		:	clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./MLX42 fclean
				@echo "Full clean finish... 🧹"

bonus		:	${LIBFT} ${MLXGL} $(OBJSB)
				@${CC} ${FLAGS} ${OBJSB} ${INCLUDESB} ${LIBRARY} -o $(NAME)
				@echo "\033[0;32m-= Ready to play with bonus! 👾 =- \033[0;0m"

.PHONY		:	all clean fclean re
