/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:42:07 by stissera          #+#    #+#             */
/*   Updated: 2023/01/09 12:21:54 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_scaled(t_game *g, t_ray *ray, mlx_texture_t *texture,
	unsigned int col)
{
	const unsigned int	x = ray->texture_pos * texture->width;
	unsigned int		y;
	unsigned int		dst_y;
	unsigned int		max_y;
	unsigned int		error;

	y = 0;
	dst_y = ft_max(0, ((int)SCREEN_Y - (int)ray->height) / 2);
	max_y = dst_y + ray->height;
	error = texture->height / 2;
	if (ray->height > SCREEN_Y)
	{
		error = (ray->height - SCREEN_Y) * texture->height / 2;
		y = error / ray->height;
		error = error % ray->height;
		max_y = SCREEN_Y ;
	}
	while (dst_y < max_y)
	{
		while (error >= ray->height && ++y)
			error -= ray->height;
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4)]
			= texture->pixels[(y * texture->width) * 4 + x * 4];
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 1]
			= texture->pixels[(y * texture->width) * 4 + x * 4 + 1];
		g->img->pixels[(col * 4) + (g->img->width * dst_y * 4) + 2]
			= texture->pixels[(y * texture->width) * 4 + x * 4 + 2];
		g->img->pixels[(col * 4) + (g->img->width * (dst_y++) * 4) + 3]
			= texture->pixels[(y * texture->width) * 4 + x * 4 + 3];
		error += texture->width;
	}	
}

void	ft_draw(t_game *g)
{
	unsigned int	ray;
	unsigned int	textures;

	ray = 0;
	ft_fill_img(g->img->pixels, g->map->color[5], 0,
		g->img->width * g->img->height / 2);
	ft_fill_img(g->img->pixels, g->map->color[4],
		g->img->width * g->img->height / 2,
		g->img->width * g->img->height);
	while (ray < SCREEN_X)
	{
		textures = ft_strchr("NSWE", g->ray[ray].dir) - "NSWE";
		ft_draw_scaled(g, &g->ray[ray], g->map->texture[textures], ray);
		ray++;
	}
}

void	ft_fill_img(void *pixels, unsigned int fill, size_t s, size_t e)
{
	unsigned int	*array;
	size_t			t;

	array = pixels;
	if (s > e)
	{
		t = e;
		e = s;
		s = t;
	}
	while (s < e)
		array[s++] = fill;
}
