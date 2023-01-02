/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:45:48 by stissera          #+#    #+#             */
/*   Updated: 2023/01/02 17:00:40 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
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
	unsigned int	size_x;
	unsigned int	size_y;
	char			**map;
	t_img			texture[6];
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	double			scale;
	t_img			*img;
	t_pos			*player;
	t_img			screen;
	t_map			*map;
	unsigned int	fov;
}	t_game;

#endif