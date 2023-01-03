/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:38 by stissera          #+#    #+#             */
/*   Updated: 2023/01/03 18:20:15 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hook(void *base)
{
	t_game	*g;

	g = (t_game *)base;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S)
		|| mlx_is_key_down(g->mlx, MLX_KEY_W))
		ft_player_move_fb(g->mlx, g->player);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A)
		|| mlx_is_key_down(g->mlx, MLX_KEY_D))
		ft_player_turn(g->mlx, g->player);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_B))
//		ft_debug(base);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_TAB))
//		base->window->minimap_o = 1;
//	else
//		base->window->minimap_o = 0;
//	ft_ray_2d(base->map, base->window, base->player, base);

	printf("player x:%f - y: %f\n player angle: %f\n", g->player->x, g->player->y, g->player->angle);
}

void	ft_player_move_fb(mlx_t *mlx, t_pos *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_S) && !mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->x -= player->dx * P_SPEED;
		player->y -= player->dy * P_SPEED;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_S)
		&& mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->x += player->dx * P_SPEED;
		player->y += player->dy * P_SPEED;
	}
}

void	ft_player_turn(mlx_t *mlx, t_pos *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle += P_TURN_SPEED;
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle -= P_TURN_SPEED;
	player->angle = ft_fixangle(player->angle);
	player->dx = cos(ft_degtorad(player->angle));
	player->dy = -sin(ft_degtorad(player->angle));
}

int	ft_fixangle(int angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

float	ft_degtorad(float deg)
{
	return (deg * M_PI / 180);
}

float	ft_radtodeg(float rad)
{
	return (rad * (180 / M_PI));
}
