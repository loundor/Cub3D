/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:05:26 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:18:24 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free_window(t_window *win)
{
	ft_free_minimap(win);
	if (win->addr)
		ft_free_str(win->addr);
	if (win->screen)
		ft_free_str(win->screen);
	if (win->server)
		ft_free_str(win->server);
	return (0);
}

int ft_free_minimap(t_window *win)
{
	if (win->minimap)
	{
		if (win->minimap->door)
			mlx_delete_image(win->mlx, win->minimap->door);
		if (win->minimap->floor)
			mlx_delete_image(win->mlx, win->minimap->floor);
		if (win->minimap->items)
			mlx_delete_image(win->mlx, win->minimap->items);
		if (win->minimap->player)
			mlx_delete_image(win->mlx, win->minimap->player);
		if (win->minimap->wall)
			mlx_delete_image(win->mlx, win->minimap->wall);
		free(win->minimap);
	}
	return (0);
}