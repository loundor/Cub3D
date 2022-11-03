/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:24 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:20:48 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook(void *param)
{
	mlx_t	*mlx;
	t_base	*player;

	player = ft_get_struct(NULL);
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
			player->player->pos_y += .03;
		else if (!mlx_is_key_down(mlx, MLX_KEY_S) && mlx_is_key_down(mlx, MLX_KEY_W))
			player->player->pos_y -= .03;
		player->window->minimap->player->instances->y = player->player->pos_y
			* (SCREEN_Y / player->map->size_y)
			+ ((SCREEN_Y / player->map->size_y) / 2) - 8;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
			player->player->pos_x -= .03;
		else if (!mlx_is_key_down(mlx, MLX_KEY_A) && mlx_is_key_down(mlx, MLX_KEY_D))
			player->player->pos_x += .03;
		player->window->minimap->player->instances->x = player->player->pos_x
			* (SCREEN_X / player->map->size_x)
			+ ((SCREEN_X / player->map->size_x) / 2) - 8;
	}
}
