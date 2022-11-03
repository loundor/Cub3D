/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:22:11 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:12:02 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_draw_minimap(t_base *base)
{
	t_minimap	*minimap;
	int			x;
	int			y;

	y = -1;
	minimap = (t_minimap *)malloc(sizeof(t_minimap));
	if (!minimap && !ft_free_base(base) && !ft_error(INIT_ALLOC))
		exit(1);
	minimap->wall = mlx_new_image(base->window->mlx, (SCREEN_X / base->map->size_x) - 2 , (SCREEN_Y / base->map->size_y) - 2);
	minimap->floor = mlx_new_image(base->window->mlx, (SCREEN_X / base->map->size_x) - 2 , (SCREEN_Y / base->map->size_y) - 2);
	minimap->player = mlx_new_image(base->window->mlx, 16, 16);
	memset(minimap->wall->pixels, 255, minimap->wall->width * minimap->wall->height * sizeof(int32_t));
	memset(minimap->floor->pixels, 128, minimap->floor->width * minimap->floor->height * sizeof(int32_t));
	memset(minimap->player->pixels, 180, 16 * 16 * sizeof(int32_t));

	while (base->map->map[++y])
	{
		x = -1;
		while (base->map->map[y][++x])
		{
			if (base->map->map[y][x] == '1')
				mlx_image_to_window(base->window->mlx, minimap->wall, x * (minimap->wall->width + 2) + 2, y * (minimap->wall->height + 2) + 2);
			else if (base->map->map[y][x] == '0')
				mlx_image_to_window(base->window->mlx, minimap->floor, x * (minimap->floor->width + 2) + 2, y * (minimap->floor->height + 2) + 2);
		}

	}
	mlx_image_to_window(base->window->mlx, minimap->player,
		base->player->pos_x * (SCREEN_X / base->map->size_x) + ((SCREEN_X / base->map->size_x) / 2) - 8 ,
		base->player->pos_y * (SCREEN_Y / base->map->size_y) + ((SCREEN_Y / base->map->size_y) / 2) - 8);
	
	base->window->minimap = minimap;
	return (0);
}