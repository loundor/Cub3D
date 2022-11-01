/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:15:09 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:15:22 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_guns(t_base *base)
{
	int		i;
	t_guns	**guns;

	guns = NULL;
	guns = (t_guns **)malloc(sizeof(t_guns *) * (NBR_OF_GUNS + 1));
	if (!guns)
		return (INIT_ALLOC);
	guns[NBR_OF_GUNS] = NULL;
	i = -1;
	while (++i < NBR_OF_GUNS)
	{
		guns[i] = (t_guns *)malloc(sizeof(t_guns) * 1);
		if (!guns[i])
			return (INIT_ALLOC);
		ft_bzero(guns[i], sizeof(t_guns));
		//if (ft_input_guns(guns[i]), i)
		//	return (INIT_GUNS);
	}
	base->guns = guns;
	return (0);
}
