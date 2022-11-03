/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:22:11 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 16:57:59 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_draw_minimap(t_base *b)
{
	t_minimap	*map;

	map = (t_minimap *)malloc(sizeof(t_minimap));
	if (!map && !ft_free_base(b) && !ft_error(INIT_ALLOC))
		exit(1);
	ft_minimap_image(map, b->window);
	ft_minimap_put_wf(b->map, map, b->window);
	ft_minimap_put_elem(map, b->window, b->player);
	b->window->minimap = map;
	return (0);
}

void	ft_minimap_image(t_minimap *mini, t_window *win)
{
	mini->wall = mlx_new_image(win->mlx, 32, 32);
	mini->floor = mlx_new_image(win->mlx, 32, 32);
	mini->player = mlx_new_image(win->mlx, 8, 8);
	memset(mini->wall->pixels, 255, mini->wall->width
		* mini->wall->height * sizeof(int32_t));
	memset(mini->floor->pixels, 128, mini->floor->width
		* mini->floor->height * sizeof(int32_t));
	memset(mini->player->pixels, 180, 8 * 8 * sizeof(int32_t));
}

void	ft_minimap_put_wf(t_map *map, t_minimap *mini, t_window *win)
{
	int			x;
	int			y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				mlx_image_to_window(win->mlx, mini->wall,
					x * (mini->wall->width + 2) + 2,
					y * (mini->wall->height + 2) + 2);
			else if (map->map[y][x] == '0')
				mlx_image_to_window(win->mlx, mini->floor,
					x * (mini->floor->width + 2) + 2,
					y * (mini->floor->height + 2) + 2);
		}
	}
}

void	ft_minimap_put_elem(t_minimap *mini, t_window *win,
	t_player *player)
{
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
	player->pos_x = (player->pos_x * 32 + 4) + 16;
	player->pos_y = (player->pos_y * 32 + 4) + 16;
	mlx_image_to_window(win->mlx, mini->player, player->pos_x, player->pos_y);
}
