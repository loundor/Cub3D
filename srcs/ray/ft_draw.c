/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:42:07 by stissera          #+#    #+#             */
/*   Updated: 2023/01/06 22:58:05 by stissera         ###   ########.fr       */
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

	char color[3];

	if (ray->dir == 'N')
	{
		color[0] = 0xff;
		color[1] = 0x00;
		color[2] = 0x00;
	}
	else if (ray->dir == 'S')
	{
		color[0] = 0x00;
		color[1] = 0xff;
		color[2] = 0x00;
	}
	else if (ray->dir == 'E')
	{
		color[0] = 0x00;
		color[1] = 0x00;
		color[2] = 0xff;
	}
	else
	{
		color[0] = 0xff;
		color[1] = 0xff;
		color[2] = 0xff;
	}
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
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4)] = color[0];//textures->pixels[(y + SCREEN_X * 4) + x * 4];
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 1] = color[1];
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 2] = color[2];
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
