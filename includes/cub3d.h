/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:45:48 by stissera          #+#    #+#             */
/*   Updated: 2023/01/03 09:10:21 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
//# include <mlx.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <math.h>

# define SCREEN_X 1024
# define SCREEN_Y 768
# define SCALE 32
# define NAME "CUB3D - stissera"

enum e_type_err
{
	ZERO,
	ARG,
	INIT_BASE,
	MAP_ERROR = 0x04,
	INIT_WINDOW = 0x08,
	INIT_ALLOC = 0x10,
	NEX_FILE = 0x20,
	BAD_COLOR = 0x40,
	BAD_START = 0x80
};

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}	t_point;

typedef struct s_pos
{
	double		x;
	double		y;
	double		angle;
	char		positioned;
}	t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heihgt;
}	t_img;

typedef struct s_map
{
	int	size_x;
	int	size_y;
	char			**map;
	mlx_texture_t	*texture[6];
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	double			scale;
	mlx_image_t		*img;
	t_pos			*player;
	t_img			screen;
	t_map			*map;
	unsigned int	fov;
}	t_game;


void	window_init(t_game *g);
int		ft_file_name(char *file);
int		ft_free_map(t_map *map);
int		ft_free_str(char *str);
int		ft_free_int(int *nbr);
int		ft_free_tab(char **tab);
int		ft_free_tab_int(int **tab);

void	hook(void *g);
int		ft_import_map(char *file, t_game *base);
int		ft_map_create(char *line, t_map *map);
int		ft_map_insert_param(char *line, t_game *g);
int		ft_file_exist(char *file);
void	*ft_get_struct(void *data);

int		ft_error(int value);

#endif