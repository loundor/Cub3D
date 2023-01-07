/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:38 by stissera          #+#    #+#             */
/*   Updated: 2023/01/07 11:55:50 by stissera         ###   ########.fr       */
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
	if (mlx_is_key_down(g->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(g->mlx, MLX_KEY_E))
		ft_player_strafe(g->mlx, g->player);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_B))
//		ft_debug(base);
//	if (mlx_is_key_down(g->mlx, MLX_KEY_TAB))
//		base->window->minimap_o = 1;
//	else
//		base->window->minimap_o = 0;
	g->player->dx = cos(g->player->angle);
	g->player->dy = sin(g->player->angle);
	ft_sum_ray(g);
	ft_draw(g);
	
	//printf("player x:%f - y: %f\n player angle: %f\n", g->player->x, g->player->y, g->player->angle);

//	for (int i = 0; i < SCREEN_X; i++)
//	{
//		printf("RAY %d\n", i);
//		printf("heigth: %u\n", g->ray[512].height);
	//	printf("texture: %f\n", g->ray[512].texture_pos);
	//	printf("dir: %c\n\n", g->ray[512].dir);
//	}
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

void	ft_player_strafe(mlx_t *mlx, t_pos *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_Q) && !mlx_is_key_down(mlx, MLX_KEY_E))
	{
		player->x += player->dy * P_SPEED;
		player->y -= player->dx * P_SPEED;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_Q)
		&& mlx_is_key_down(mlx, MLX_KEY_E))
	{
		player->x -= player->dy * P_SPEED;
		player->y += player->dx * P_SPEED;
	}
}

void	ft_player_turn(mlx_t *mlx, t_pos *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle -= P_SPEED / 4;
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle += P_SPEED / 4;
	player->angle = ft_fixangle(player->angle);
}

double	ft_fixangle(double angle)
{
	if (angle < 0)
		angle += (M_PI * 2);
	else if (angle > M_PI * 2)
		angle -= (M_PI * 2);
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
