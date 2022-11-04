/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:24 by stissera          #+#    #+#             */
/*   Updated: 2022/11/04 14:11:01 by stissera         ###   ########.fr       */
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
		ft_player_turn(mlx, base->player, base->window);
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

void	ft_player_turn(mlx_t *mlx, t_player *player, t_window *win)
{
	if (mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle -= 5;
	else if (!mlx_is_key_down(mlx, MLX_KEY_A)
		&& mlx_is_key_down(mlx, MLX_KEY_D))
		player->angle += 5;
	if (player->angle > 359)
		player->angle -=360;
	if (player->angle < 0)
		player->angle +=360;
	player->delta_x = cos(player->angle *M_PI / 180.0);
	player->delta_y = sin(player->angle *M_PI / 180.0);
	memset(win->minimap->player->pixels, 180, 8 * 8 * sizeof(int32_t));
	mlx_put_pixel(win->minimap->player, 4 - (player->delta_x * 4), 4 - (player->delta_y * 4), 0x00FF00FF);
	mlx_put_pixel(win->minimap->player, 4 - (player->delta_x * 3), 4 - (player->delta_y * 3), 0x00FF00FF);
	mlx_put_pixel(win->minimap->player, 4 - (player->delta_x * 2), 4 - (player->delta_y * 2), 0x00FF00FF);
	mlx_put_pixel(win->minimap->player, 4 - (player->delta_x * 1), 4 - (player->delta_y * 1), 0x00FF00FF);
	mlx_put_pixel(win->minimap->player, 4 - (player->delta_x), 4 - (player->delta_y), 0x00FF00FF);
	win->minimap->player->instances->y = player->pos_y;
	win->minimap->player->instances->x = player->pos_x;
}
