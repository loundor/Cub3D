/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:34:36 by stissera          #+#    #+#             */
/*   Updated: 2023/01/18 10:46:04 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

mlx_texture_t	*ft_atexture(t_atexture *texture, mlx_texture_t *t)
{
	static long		old;
	long			clock;
	mlx_texture_t	*ret;

	gettimeofday(&texture->timer, NULL);
	clock = (texture->timer.tv_sec * 1000) + (texture->timer.tv_usec / 1000);
	if (clock - old > texture->n_time)
	{
		ret = texture->frame[texture->nframe++];
		if (texture->nframe == texture->nbr_frame)
			texture->nframe = 0;
		old = clock;
		return (ret);
	}
	return (t);
}

void	ft_atexture_init(t_game	*g)
{
	g->map->animed = (t_atexture *)malloc(sizeof(t_atexture) * NBR_TEXTURE);
	if (!g->map->animed)
		exit (0 * ft_error(INIT_ALLOC));
	g->map->animed->nbr_frame = 4;
	g->map->animed->n_time = 400;
	g->map->animed->nframe = 0;
	g->map->animed->frame = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* g->map->animed->nbr_frame);
	if (!g->map->animed[0].frame)
		exit (0 * ft_error(INIT_ALLOC));
	g->map->animed->frame[0] = mlx_load_png("./textures/watter/FWATER1.png");
	g->map->animed->frame[1] = mlx_load_png("./textures/watter/FWATER2.png");
	g->map->animed->frame[2] = mlx_load_png("./textures/watter/FWATER3.png");
	g->map->animed->frame[3] = mlx_load_png("./textures/watter/FWATER4.png");
	g->map->texture[6] = g->map->animed->frame[0];
}

int	ft_free_atexture(t_map *map)
{
	int	i;

	i = -1;
	if (!map->animed)
		return (0);
	while (++i < map->animed->nbr_frame)
		mlx_delete_texture(map->animed->frame[i]);
	free(map->animed->frame);
	free(map->animed);
	return (0);
}
