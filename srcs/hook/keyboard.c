/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:24 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 17:09:25 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook(void *param)
{
	mlx_t	*mlx;
	t_base	*base;

	base = ft_get_struct(NULL);
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_W))
		ft_player_move_fb(mlx, base->player, base->window);
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_D))
		ft_player_turn(mlx, base->player);
	if (mlx_is_key_down(mlx, MLX_KEY_B))
		ft_debug(base);
}

void	ft_player_move_fb(mlx_t *mlx, t_player *player, t_window *win)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->pos_x += player->delta_x;
		player->pos_y += player->delta_y;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_S)
		&& mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->pos_x -= player->delta_x;
		player->pos_y -= player->delta_y;
	}
	win->minimap->player->instances->y = player->pos_y;
	win->minimap->player->instances->x = player->pos_x;
}

void	ft_player_turn(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
	{
		player->angle -= .03;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
	{
		player->angle += .03;
		if (player->angle > (2 * PI))
			player->angle -= 2 * PI;
	}
	player->delta_x = cos(player->angle);
	player->delta_y = sin(player->angle);
}
