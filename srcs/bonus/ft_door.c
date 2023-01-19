/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:39:02 by tkempf-e          #+#    #+#             */
/*   Updated: 2023/01/19 17:58:29 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_door(t_game *g)
{
	t_door *door;
	t_door	*bak;

	door = g->door;
	while (door)
	{
		if (((g->time.tv_sec * 1000) + (g->time.tv_usec / 1000)) - \
			((door->start_at.tv_sec * 1000) + (door->start_at.tv_usec / 1000)) > \
			door->close_time && \
			((int)g->player->x != door->x || (int)g->player->y != door->y))
		{
			g->map->map[door->y][g->door->x] = 'D';
			if (door->next == NULL && door->prev == NULL)
			{
				g->door = NULL;
				free(door);
				door = NULL;
			}
			else if (door->prev == NULL && door->next != NULL)
			{
				g->door = door->next;
				g->door->prev = NULL;
				free(door);
				door = g->door;				
			}
			else if (door->prev != NULL && door->next == NULL)
			{
				door->prev->next = NULL;
				free(door);
				return;
			}
			else if (door->prev != NULL && door->next != NULL)
			{
				bak = door;
				door->prev->next = door->next;
				door->next->prev = door->prev;
				door = door->next;
				free(bak);
				bak = NULL;
			}
			continue;
		}
		door = door->next;
	}
}

static void	ft_open_door(int y, int x, t_map *map)
{
	t_game	*g;
	t_door	*new;
	t_door	*exist;

	g = (t_game *)ft_get_struct(NULL);
	map->map[y][x] = 'S';
	new = (t_door *)malloc(sizeof(t_door));
	if (!new)
		exit(ft_error(INIT_ALLOC));
	*new = (t_door){NULL, x, y, {0,0}, 5000, NULL};
	gettimeofday(&new->start_at, NULL);
	if (!g->door)
	{
		g->door = new;
		return ;
	}
	exist = g->door;
	while (exist->next)
		exist = exist->next;
	new->prev = exist;
	exist->next = new;
	return ;
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
