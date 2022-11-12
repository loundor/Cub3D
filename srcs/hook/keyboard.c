/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:24 by stissera          #+#    #+#             */
/*   Updated: 2022/11/12 02:01:25 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook(void *param)
{
	mlx_t	*mlx;
	t_base	*base;

	base = (t_base *)ft_get_struct(NULL);
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_W))
		ft_player_move_fb(mlx, base->player);
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_D))
		ft_player_turn(mlx, base->player);
	if (mlx_is_key_down(mlx, MLX_KEY_B))
		ft_debug(base);
	if (mlx_is_key_down(mlx, MLX_KEY_TAB))
		base->window->minimap_o = 1;
	else
		base->window->minimap_o = 0;
	ft_ray_2d(base->map, base->window, base->player, base);
}

void	ft_player_move_fb(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->pos_x -= player->delta_x * P_SPEED;
		player->pos_y -= player->delta_y * P_SPEED;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_S)
		&& mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->pos_x += player->delta_x * P_SPEED;
		player->pos_y += player->delta_y * P_SPEED;
	}
}

void	ft_player_turn(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle += P_TURN_SPEED;
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle -= P_TURN_SPEED;
	player->angle = ft_fixangle(player->angle);
	player->delta_x = cos(ft_degtorad(player->angle));
	player->delta_y = -sin(ft_degtorad(player->angle));
}
