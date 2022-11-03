/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:22:11 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 12:35:48 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_draw_minimap(t_base *b)
{
	t_minimap	*map;
	int			x;
	int			y;

	y = -1;
	map = (t_minimap *)malloc(sizeof(t_minimap));
	if (!map && !ft_free_base(b) && !ft_error(INIT_ALLOC))
		exit(1);
	map->wall = mlx_new_image(b->window->mlx, (SCREEN_X / b->map->size_x) - 2 , (SCREEN_Y / b->map->size_y) - 2);
	map->floor = mlx_new_image(b->window->mlx, (SCREEN_X / b->map->size_x) - 2 , (SCREEN_Y / b->map->size_y) - 2);
	map->player = mlx_new_image(b->window->mlx, 16, 16);
	memset(map->wall->pixels, 255, map->wall->width * map->wall->height * sizeof(int32_t));
	memset(map->floor->pixels, 128, map->floor->width * map->floor->height * sizeof(int32_t));
	memset(map->player->pixels, 180, 16 * 16 * sizeof(int32_t));

	while (b->map->map[++y])
	{
		x = -1;
		while (b->map->map[y][++x])
		{
			if (b->map->map[y][x] == '1')
				mlx_image_to_window(b->window->mlx, map->wall, x * (map->wall->width + 2) + 2, y * (map->wall->height + 2) + 2);
			else if (b->map->map[y][x] == '0')
				mlx_image_to_window(b->window->mlx, map->floor, x * (map->floor->width + 2) + 2, y * (map->floor->height + 2) + 2);
		}

	}
	b->player->delta_x = cos(b->player->angle);
	b->player->delta_y = sin(b->player->angle);
	b->player->pos_x *= (SCREEN_X / b->map->size_x) + ((SCREEN_X / b->map->size_x) / 2) - 8;
	b->player->pos_y *= (SCREEN_Y / b->map->size_y) + ((SCREEN_Y / b->map->size_y) / 2) - 8;
	mlx_image_to_window(b->window->mlx, map->player, b->player->pos_x, b->player->pos_y);
	b->window->minimap = map;
	return (0);
}