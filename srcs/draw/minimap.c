/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:22:11 by stissera          #+#    #+#             */
/*   Updated: 2022/11/12 02:46:06 by stissera         ###   ########.fr       */
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
	t_map	*map;

	map = (t_map *)ft_get_struct("map");
	mini->screen = mlx_new_image(win->mlx, map->size_x
			* SCALE, map->size_y * SCALE);
	mini->wall = mlx_new_image(win->mlx, SCALE, SCALE);
	mini->floor = mlx_new_image(win->mlx, SCALE, SCALE);
	mini->player = mlx_new_image(win->mlx, 8, 8);
	ft_memset(mini->screen->pixels, 0, mini->screen->width
		* mini->screen->height * sizeof(int32_t));
	ft_memset(mini->wall->pixels, 255, mini->wall->width
		* mini->wall->height * sizeof(int32_t));
	ft_memset(mini->floor->pixels, 128, mini->floor->width
		* mini->floor->height * sizeof(int32_t));
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
					x * (mini->wall->width),
					y * (mini->wall->height));
			else if (map->map[y][x] == '0')
				mlx_image_to_window(win->mlx, mini->floor,
					x * mini->floor->width,
					y * mini->floor->height);
		}
	}
}

void	ft_minimap_put_elem(t_minimap *mini, t_window *win,
	t_player *player)
{
	player->delta_x = cos(ft_degtorad(ft_fixangle(player->angle)));
	player->delta_y = -sin(ft_degtorad(ft_fixangle(player->angle)));
	player->pos_x = player->pos_x * SCALE + player->pos_x + (SCALE / 2);
	player->pos_y = player->pos_y * SCALE + player->pos_y + (SCALE / 2);
	mlx_image_to_window(win->mlx, mini->screen, 0, 0);
	mlx_image_to_window(win->mlx, mini->player, player->pos_x, player->pos_y);
}

void	ft_player_mini_set(t_base *b, float x, float y, int color)
{
	memset(b->window->minimap->player->pixels, 0, 8 * 8 * sizeof(int32_t));
	mlx_put_pixel(b->window->minimap->player, 4 + (b->player->delta_x * 4),
		4 + (b->player->delta_y * 4), 0x00FF00FF);
	mlx_put_pixel(b->window->minimap->player, 4 + (b->player->delta_x * 3),
		4 + (b->player->delta_y * 3), 0x00FF00FF);
	mlx_put_pixel(b->window->minimap->player, 4 + (b->player->delta_x * 2),
		4 + (b->player->delta_y * 2), 0x00FF00FF);
	mlx_put_pixel(b->window->minimap->player, 4 + (b->player->delta_x * 1),
		4 + (b->player->delta_y * 1), 0x00FF00FF);
	mlx_put_pixel(b->window->minimap->player, 4 + (b->player->delta_x),
		4 + (b->player->delta_y), 0x00FF00FF);
	mlx_put_pixel(b->window->minimap->screen, x, y, color);
	b->window->minimap->player->instances->y = b->player->pos_y;
	b->window->minimap->player->instances->x = b->player->pos_x;
	ft_player_mini(b);
}

void	ft_player_mini(t_base *b)
{
	if (b->window->minimap_o == 0 && ft_set_all_instances(b->window->minimap->wall, 0)
		&& ft_set_all_instances(b->window->minimap->floor, 0)
		&& ft_set_all_instances(b->window->minimap->player, 0))
		b->window->minimap->screen->instances->enabled = 0;
	else if (ft_set_all_instances(b->window->minimap->wall, 1)
		&& ft_set_all_instances(b->window->minimap->floor, 1)
		&& ft_set_all_instances(b->window->minimap->player, 1))
		b->window->minimap->screen->instances->enabled = 1;
}

int	ft_set_all_instances(mlx_image_t *image, int put)
{
	int	nbr;

	nbr = -1;
	while (++nbr < image->count)
		image->instances[nbr].enabled = put;
	return (nbr);
}
