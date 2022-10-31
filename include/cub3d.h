/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:30:09 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 00:00:11 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define	CUB3D_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <errno.h>
#include <error.h>
//#include <mlx.h>

// Load structure
#include	"./player.h"
#include	"./window.h"
#include	"./caractere.h"
#include	"./items.h"
#include	"./guns.h"
#include	"./ammo.h"
#include	"./map.h"


#define	NBR_OF_ENEMY 9
#define	NBR_OF_AMMO 14
#define	NBR_OF_ITEMS 15
#define	NBR_OF_GUNS	8
#define	SCREEN_X 1024
#define SCREEN_Y 768
#define GAME_NAME "Cub3D by stissera"
#define FOV 66
#define FPS 50

//Color define
#define OPAQUE 0xFF
#define	HIDE 0x0 << 8

enum TYPE_ERR
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
	BAD_COLOR = 0xAA
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
} t_base;

// Error, free and exit
int	ft_error(int value);
int	ft_free_str(char *str);
int	ft_free_tab(char **tab);
int	ft_free_base(t_base *base);

// Make structure
int	ft_s_player(t_base *base);
int	ft_s_enemy(t_base *base);
int	ft_s_guns(t_base *base);
int	ft_s_ammo(t_base *base);
int	ft_s_items(t_base *base);
int	ft_s_map(t_base *base);
int	ft_s_window(t_base *base);

//check name file map
int	ft_file_name(char *file);

// Import and check map
int		ft_import_map (char *file, t_base *base);
int		ft_read_line_map(char *buffer, char **line, int *w_map, t_base *base);
int		ft_set_map(t_base *base, char *line, int inmap);
int		ft_map_insert_param(char *line, t_base *base);
int		ft_putarg_in(char *line, void **texture, int *type);
int		ft_putarg_rgb(char *line,void **texture, int *type);
int		ft_test_file_if_exist(char *file);
void	ft_add_color_texture(unsigned char *rgba, void **texture);

int ft_load_file (char *file);


t_base	*ft_get_struct(void *data);

#endif