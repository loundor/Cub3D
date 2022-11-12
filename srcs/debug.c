/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:27:28 by stissera          #+#    #+#             */
/*   Updated: 2022/11/05 16:27:12 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_debug(t_base *base)
{
	if (DEBUG)
	{
		printf("Start position: %c\nDelta x : %f\nDelta y: %f\n\
Pos_x: %f\nPos_y: %f\nAngle: %d\nRad: %f\n Tan: %f\n",
			base->player->start_position,
			base->player->delta_x,
			base->player->delta_y,
			base->player->pos_x,
			base->player->pos_y,
			base->player->angle,
			(float)base->player->angle * M_PI/180,
			tan(base->player->angle * M_PI/180));
	}
	return (0);
}
