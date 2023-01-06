/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:42:07 by stissera          #+#    #+#             */
/*   Updated: 2023/01/06 22:26:28 by stissera         ###   ########.fr       */
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
		g->img->pixels[(col * 4) + (g->img->width * dst_y++ * 4) + 3] = 0xFF;//textures->pixels[(y + SCREEN_X * 4) + x * 4];
		//g->img->pixels[SCREEN_X * 4 * dst_y++ + (col * 3) + 1] = 0xFF; //textures->pixels[(y + SCREEN_X * 4) + x * 4 + 1];
		//g->img->pixels[SCREEN_X * 4 * dst_y++ + (col * 3) + 2] = 0x00; //textures->pixels[(y + SCREEN_X * 4) + x * 4 + 2];
		//g->img->pixels[SCREEN_X * 4 * dst_y++ + (col * 3) + 3] = 0xFF; //textures->pixels[(y + SCREEN_X * 4) + x * 4 + 2];

//		g->img->pixels[((SCREEN_X + dst_y) * 4) + (col * 3) + 3] = 0xa8; //textures->pixels[(y + SCREEN_X * 4) + x * 4 + 3];
		error += SCREEN_Y;
		//mlx_put_pixel(g->img, col, dst_y, 0xff0000ff);
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
