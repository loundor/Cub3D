/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:12:15 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:12:37 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_player(t_base *base)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player) * 1);
	if (!player)
		return (INIT_ALLOC);
	ft_bzero(player, sizeof(t_player));
	base->player = player;
	return (0);
}
