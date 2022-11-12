/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:34:44 by stissera          #+#    #+#             */
/*   Updated: 2022/11/12 02:59:27 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t	*ft_draw_line(int32_t *xy, int32_t *dy,	int size,
	int32_t color)
{
	(void)xy;
	(void)dy;
	(void)size;
	(void)color;
/* 	mlx_image_t	*line;
	t_base		*b;

	b = ft_get_struct(NULL);
	line = mlx_new_image(b->window->mlx, xy[0], xy[1]);

	
	return (line); */
	return (NULL);
}






// Bressenham fdf

void	draw_line(t_global *m)
{
	m->line->px = abs(m->line->x1 - m->line->x);
	m->line->py = abs(m->line->y1 - m->line->y);
	m->line->dx = 2 * m->line->px;
	m->line->dy = 2 * m->line->py;
	m->line->dx1 = m->line->px;
	m->line->dy1 = m->line->py;
	m->line->xi = 1;
	m->line->yi = 1;
	if (m->line->x > m->line->x1)
		m->line->xi = -1;
	if (m->line->y > m->line->y1)
		m->line->yi = -1;
	if (m->line->dx1 > m->line->dy1)
		draw_line_b(m);
	if (m->line->dx1 < m->line->dy1)
		draw_line_s(m);
}

void	draw_line_b(t_global *m)
{
	int	i;

	i = -1;
	while (++i <= m->line->dx1)
	{
		if (m->line->x > 0 && m->line->x < m->winx
			&& m->line->y > 0 && m->line->y < m->winy)
		{
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8)] = m->line->color[1];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 1] = m->line->color[2];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 2] = m->line->color[3];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 3] = m->line->color[0];
		}
		m->line->x += m->line->xi;
		m->line->px -= m->line->dy;
		if (m->line->px < 0)
		{
			m->line->y += m->line->yi;
			m->line->px += m->line->dx;
		}
	}
}

void	draw_line_s(t_global *m)
{
	int	i;

	i = -1;
	while (++i <= m->line->dy1)
	{
		if (m->line->x > 0 && m->line->x < m->winx
			&& m->line->y > 0 && m->line->y < m->winy)
		{
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8)] = m->line->color[1];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 1] = m->line->color[2];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 2] = m->line->color[3];
			m->data[((m->line->y * m->size_img)) + m->line->x
				* (m->bpp / 8) + 3] = m->line->color[0];
		}
		m->line->y += m->line->yi;
		m->line->py -= m->line->dx;
		if (m->line->py < 0)
		{
			m->line->x += m->line->xi;
			m->line->py += m->line->dy;
		}
	}
}