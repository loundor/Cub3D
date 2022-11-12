/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:09:48 by stissera          #+#    #+#             */
/*   Updated: 2022/11/12 02:48:50 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_ray_2d(t_map *map, t_window *win, t_player *play, t_base *b)
{
	int	loop;

	win->minimap->ray_a = play->angle + (FOV / 2);
	loop = -1;
	while (++loop < FOV)
	{
		ft_check_ver(win->minimap, map, play);
		ft_check_hor(win->minimap, map, play);
		if (cos(ft_degtorad(win->minimap->ray_a))
			* (win->minimap->ray_x - play->pos_x)
			- sin(ft_degtorad(win->minimap->ray_a))
			* (win->minimap->ray_y - play->pos_y)
			< cos(ft_degtorad(win->minimap->ray_a))
			* (win->minimap->ray_x - play->pos_x)
			- sin(ft_degtorad(win->minimap->ray_a))
			* (win->minimap->ray_hy - play->pos_y)
			&& win->minimap->ray_x != play->pos_x)
			ft_player_mini_set(b, win->minimap->ray_x, win->minimap->ray_y,
				0xFF00FF);
		else if (win->minimap->ray_y != play->pos_y)
			ft_player_mini_set(b, win->minimap->ray_hx, win->minimap->ray_hy,
				0x00FFFF);
		win->minimap->ray_a = ft_fixangle(win->minimap->ray_a - 1);
	}
	return (0);
}

void	ft_check_ver(t_minimap *mm, t_map *map, t_player *p)
{
	int	limit;

	limit = 0;
	mm->tan = tan(ft_degtorad(mm->ray_a));
	if (cos(ft_degtorad(mm->ray_a)) > 0.001)
	{
		mm->ray_x = (((int)p->pos_x >> 5) << 5) + SCALE;
		mm->ray_y = (p->pos_x - mm->ray_x) * mm->tan + p->pos_y;
		mm->off_x = SCALE;
	}
	else if (cos(ft_degtorad(mm->ray_a)) < -0.001)
	{
		mm->ray_x = (((int)p->pos_x >> 5) << 5) - 0.0001;
		mm->ray_y = (p->pos_x - mm->ray_x) * mm->tan + p->pos_y;
		mm->off_x = -1 * SCALE;
	}
	else
	{
		mm->ray_x = p->pos_x;
		mm->ray_y = p->pos_y;
		limit = map->size_y;
	}
		mm->off_y = -mm->off_x * mm->tan;
	while (limit < map->size_y)
	{
		mm->max_x = (int)(mm->ray_x) >> 5;
		mm->max_y = (int)(mm->ray_y) >> 5;
		if (mm->max_x >= 0 && mm->max_x < map->size_x
			&& mm->max_y >= 0 && mm->max_y < map->size_y
			&& map->map[mm->max_y][mm->max_x] == '1')
			limit = map->size_y;
		else
		{
			mm->ray_x += mm->off_x;
			mm->ray_y += mm->off_y;
			limit++;
		}
	}
}

void	ft_check_hor(t_minimap *mm, t_map *map, t_player *p)
{
	int	limit;

	limit = 0;
	mm->tan = 1.0 / mm->tan;
	if (sin(ft_degtorad(mm->ray_a)) > 0.001)
	{
		mm->ray_hy = (((int)p->pos_y >> 5) << 5) - 0.0001;
		mm->ray_hx = (p->pos_y - mm->ray_hy) * mm->tan + p->pos_x;
		mm->off_y = -1 * SCALE;
	}
	else if (sin(ft_degtorad(mm->ray_a)) < -0.001)
	{
		mm->ray_hy = (((int)p->pos_y >> 5) << 5) + SCALE;
		mm->ray_hx = (p->pos_y - mm->ray_hy) * mm->tan + p->pos_x;
		mm->off_y = SCALE;
	}
	else
	{
		mm->ray_hx = p->pos_x;
		mm->ray_hy = p->pos_y;
		limit = map->size_x;
	}
		mm->off_x = -mm->off_y * mm->tan;
	while (limit < map->size_x)
	{
		mm->max_x = (int)(mm->ray_hx) >> 5;
		mm->max_y = (int)(mm->ray_hy) >> 5;
		if (mm->max_x >= 0 && mm->max_x < map->size_x
			&& mm->max_y >= 0 && mm->max_y < map->size_y
			&& map->map[mm->max_y][mm->max_x] == '1')
			limit = map->size_x;
		else
		{
			mm->ray_hx += mm->off_x;
			mm->ray_hy += mm->off_y;
			limit++;
		}
	}
}
