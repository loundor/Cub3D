/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:13:54 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:14:05 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_ammo(t_base *base)
{
	int		i;
	t_ammo	**ammo;

	ammo = NULL;
	ammo = (t_ammo **)malloc(sizeof(t_ammo *) * (NBR_OF_AMMO + 1));
	if (!ammo)
		return (INIT_ALLOC);
	ammo[NBR_OF_AMMO] = NULL;
	i = -1;
	while (++i < NBR_OF_AMMO)
	{
		ammo[i] = (t_ammo *)malloc(sizeof(t_ammo) * 1);
		if (!ammo[i])
			return (INIT_ALLOC);
		ft_bzero(ammo[i], sizeof(t_ammo));
		//if (ft_input_ammo(ammo[i]), i)
		//	return (INIT_AMMO);
	}
	base->ammo = ammo;
	return (0);
}
