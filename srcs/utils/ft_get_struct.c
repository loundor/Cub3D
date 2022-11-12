/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:25 by stissera          #+#    #+#             */
/*   Updated: 2022/11/11 23:40:02 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	*ft_get_struct(void *data)
{
	static int			reload;
	static t_base		*base;

	if (reload != 1)
	{
		base = (t_base *)data;
		reload = 1;
	}
	if (data == NULL)
		return (base);
	if (!ft_strncmp(data, "player", 7))
		return ((t_player *)base->player);
	if (!ft_strncmp(data, "window", 7))
		return ((t_window *)base->window);
	if (!ft_strncmp(data, "caractere", 10))
		return ((t_map *)base->caractere);
	if (!ft_strncmp(data, "items", 6))
		return ((t_player *)base->items);
	if (!ft_strncmp(data, "guns", 5))
		return ((t_window *)base->guns);
	if (!ft_strncmp(data, "ammo", 5))
		return ((t_map *)base->ammo);
	if (!ft_strncmp(data, "map", 4))
		return ((t_map *)base->map);
	return (NULL);
}
