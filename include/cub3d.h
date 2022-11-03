/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:30:09 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:18:04 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include	<errno.h>
# include "./color.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Load structure
# include "./player.h"
# include "./window.h"
# include "./caractere.h"
# include "./items.h"
# include "./guns.h"
# include "./ammo.h"
# include "./map.h"

# define NBR_OF_ENEMY	9
# define NBR_OF_AMMO	14
# define NBR_OF_ITEMS	15
# define NBR_OF_GUNS	8
# define SCREEN_X		1024
# define SCREEN_Y		768
# define GAME_NAME		"Cub3D by stissera & nobody"
# define FOV 66
# define FPS 50

//Color define
# define OPAQUE	0xFF
# define HIDE	0x0 << 8

enum e_type_err
{
	ZERO,
	ARG,
	INIT_BASE,
	MAP_ERROR = 0x04,
	INIT_MONSTER = 0x08,
	INIT_GUNS = 0x10,
	INIT_AMMO = 0x20,
	INIT_ITEMS = 0x40,
	INIT_WINDOW = 0x80,
	INIT_ALLOC = 0xFF,
	NEX_FILE = 0xA0,
	BAD_COLOR = 0xAA,
	BAD_START = 0xB0
};

typedef struct s_base
{
	struct s_player		*player;
	struct s_window		*window;
	struct s_caractere	**caractere;
	struct s_items		**items;
	struct s_guns		**guns;
	struct s_ammo		**ammo;
	struct s_map		*map;
}	t_base;

// Error, free and exit
int		ft_error(int value);
int		ft_free_str(char *str);
int		ft_free_tab(char **tab);
int		ft_free_int(int *nbr);
int		ft_free_tab_int(int **tab);
int		ft_free_base(t_base *base);
int		ft_free_root_base(t_base *base);
int		ft_free_window(t_window *win);
int		ft_free_minimap(t_window *win);
int		ft_free_caractere(t_caractere *car);
int		ft_free_car_sprite(t_sprite *sprite);
int		ft_free_items(t_items *items);
int		ft_free_guns(t_guns *guns);
int		ft_free_ammo(t_ammo *ammo);
int		ft_free_map(t_map *map);

// Make structure
int		ft_strart_screen(t_base *base, char **av);
int		ft_s_player(t_base *base);
int		ft_s_enemy(t_base *base);
int		ft_s_guns(t_base *base);
int		ft_s_ammo(t_base *base);
int		ft_s_items(t_base *base);
int		ft_s_map(t_base *base);
int		ft_s_window(t_base *base);

//check name file map
int		ft_file_name(char *file);

// Import and check map
int		ft_import_map(char *file, t_base *base);
int		ft_read_line_map(char *buffer, char **line, int *w_map, t_base *base);
int		ft_set_map(t_base *base, char *line, int inmap);
//param
int		ft_map_insert_param(char *line, t_base *base);
int		ft_map_param_no(char *line, t_base *base);
int		ft_map_param_so(char *line, t_base *base);
int		ft_map_param_we(char *line, t_base *base);
int		ft_map_param_ea(char *line, t_base *base);
int		ft_map_param_f(char *line, t_base *base);
int		ft_putarg_in(char *line, void **texture, int *type);
int		ft_putarg_rgb(char *line, void **texture, int *type);
void	ft_add_color_texture(unsigned char *rgba, void **texture);
// map
int		ft_map_create(char *line, t_map *map);
int		ft_map_first(t_map *map, char *line, char **create);
int		ft_realloc_map(t_map *map, char *line, char **create);
void	ft_input_line_map(char **line, char **create, int *l, int *c);

// Utils
int		ft_test_file_if_exist(char *file);
t_base	*ft_get_struct(void *data);

// Drawing function
int	ft_draw_minimap(t_base *base);

//Hook
void	hook(void *param);
// Debug
// Print before exit main and before free;
void	ft_print_debug(t_base *base);

#endif