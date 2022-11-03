/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:53:03 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 01:43:41 by stissera         ###   ########.fr       */
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
}	t_window;

#endif
