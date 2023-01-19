/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 14:45:39 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_open_door(int y, int x, t_map *map)
{
	map->map[y][x] = 'S';
}

void	ft_door(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_F))
	{
		if (g->map->map[(int)g->player->y + 1][(int)g->player->x] == 'D' && \
			(int)g->player->y + 1 != g->map->size_y - 1 && \
			(g->player->angle > M_PI_4 && g->player->angle < M_PI_4 * 3))
			ft_open_door((int)g->player->y + 1, (int)g->player->x, g->map);
		if (g->map->map[(int)g->player->y - 1][(int)g->player->x] == 'D' && \
			(int)g->player->y - 1 != 0 && \
			(g->player->angle > M_PI_4 * 5 && g->player->angle < M_PI_4 * 7))
			ft_open_door((int)g->player->y - 1, (int)g->player->x, g->map);
		if (g->map->map[(int)g->player->y][(int)g->player->x + 1] == 'D' && \
			(int)g->player->x + 1 != g->map->size_x - 1 &&
			(g->player->angle > M_PI_4 * 7 || g->player->angle < M_PI_4))
			ft_open_door((int)g->player->y, (int)g->player->x + 1, g->map);
		if (g->map->map[(int)g->player->y][(int)g->player->x - 1] == 'D' && \
			(int)g->player->x - 1 != 0 && \
			(g->player->angle > M_PI_4 * 3 && g->player->angle < M_PI_4 * 5))
			ft_open_door((int)g->player->y, (int)g->player->x - 1, g->map);
	}
}
