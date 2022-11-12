/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:53:03 by stissera          #+#    #+#             */
/*   Updated: 2022/11/12 02:00:40 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_minimap
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*door;
	mlx_image_t	*items;
	mlx_image_t	*ray;
	mlx_image_t	*screen;
	float		ray_x;
	float		ray_y;
	float		ray_hx;
	float		ray_hy;
	float		ray_a;
	float		off_x;
	float		off_y;
	int			max_x;
	int			max_y;
	float		tan;
	
}	t_minimap;

typedef struct s_window
{
	mlx_t				*mlx;
	void				*server;
	int					bpp;
	int					line_lenght;
	int					endian;
	char				*addr;
	void				*screen;
	struct s_minimap	*minimap;
	int					scale;
	int					minimap_o;
}	t_window;

#endif
