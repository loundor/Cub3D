/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:24 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 12:32:31 by stissera         ###   ########.fr       */
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
		{
			player->player->pos_x += player->player->delta_x;
			player->player->pos_y += player->player->delta_y;
		}
		else if (!mlx_is_key_down(mlx, MLX_KEY_S) && mlx_is_key_down(mlx, MLX_KEY_W))
		{
			player->player->pos_x -= player->player->delta_x;
			player->player->pos_y -= player->player->delta_y;
		}
		player->window->minimap->player->instances->y = player->player->pos_y;
		player->window->minimap->player->instances->x = player->player->pos_x;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		{
			player->player->angle -= .03;
			if (player->player->angle < 0)
				player->player->angle += 2 * PI;
		}
		else if (!mlx_is_key_down(mlx, MLX_KEY_A) && mlx_is_key_down(mlx, MLX_KEY_D))
		{
			player->player->angle += .03;
			if (player->player->angle > (2 * PI))
				player->player->angle -= 2 * PI;
		}
		player->player->delta_x = cos(player->player->angle); // why 5?
		player->player->delta_y = sin(player->player->angle);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_B))
		ft_debug(player);
}
