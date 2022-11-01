/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:14:33 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:14:48 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_items(t_base *base)
{
	int		i;
	t_items	**items;

	items = NULL;
	items = (t_items **)malloc(sizeof(t_items *) * (NBR_OF_ITEMS + 1));
	if (!items)
		return (INIT_ALLOC);
	items[NBR_OF_ITEMS] = NULL;
	i = -1;
	while (++i < NBR_OF_ITEMS)
	{
		items[i] = (t_items *)malloc(sizeof(t_items) * 1);
		if (!items[i])
			return (INIT_ALLOC);
		ft_bzero(items[i], sizeof(t_items));
		//if (ft_input_items(items[i]), i)
		//	return (INIT_ITEMS);
	}
	base->items = items;
	return (0);
}
