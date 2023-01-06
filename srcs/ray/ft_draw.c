/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:42:07 by stissera          #+#    #+#             */
/*   Updated: 2023/01/06 22:30:02 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_max(int i, int j)
{
	if (i < j)
		return (j);
	return i;
}
void	ft_draw_scaled(t_game *g, t_ray *ray, mlx_texture_t *texture, unsigned int col)
{
	//const unsigned int	x = ray->texture_pos * texture->width;
	(void)texture;
	unsigned int		y;
	unsigned int		dst_y;
	unsigned int		max_y;
	unsigned int		error;

	//mlx_image_t *textures = mlx_texture_to_image(g->mlx, texture);
	y = 0;
	dst_y = ft_max(0, ((int)SCREEN_Y - (int)ray->height) / 2);
	max_y = dst_y + ray->height;
	error = SCREEN_Y / 2;
	if (ray->height > SCREEN_Y)
	{
		error = (ray->height - SCREEN_Y) * SCREEN_Y / 2;
		y = error / ray->height;
		error = error % ray->height;
		max_y = SCREEN_Y;
	}
	while (dst_y < max_y)
	{
		while (error >= ray->height && ++y)
			error -= ray->height;
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4)] = 0xFF;//textures->pixels[(y + SCREEN_X * 4) + x * 4];
		g->img->pixels[(col * 4) + (g->img->width * dst_y++ * 4) + 3] = 0xFF;
		error += SCREEN_Y;
	}
	
}

void	ft_draw(t_game *g)
{
	unsigned int	ray;
	unsigned int	textures;

	ray = 0;
	memset(g->img->pixels, 0,g->img->width * g->img->height * 4);
	while (ray < SCREEN_X)
	{

		textures = ft_strchr("NSWE", g->ray[ray].dir) - "NSWE";
		ft_draw_scaled(g, &g->ray[ray], g->map->texture[textures], ray);
		ray++;
	}

}
