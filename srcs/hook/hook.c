/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:38 by stissera          #+#    #+#             */
/*   Updated: 2023/01/02 23:59:54 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hook(void *base)
{
	mlx_t	*mlx;
	t_game *g;

	mlx = base;
	g = (t_game *)ft_get_struct(NULL);
	if (mlx_is_key_down(mlx, MLX_KEY_TAB))
		printf("ok");

	mlx_image_t *test = mlx_texture_to_image(mlx, g->map->texture[1]);
	mlx_image_to_window(g->mlx, test, 50, 50);
	//ft_ray_2d(base->map, base->img, base->player, base);
}
