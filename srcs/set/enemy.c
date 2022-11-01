/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:13:20 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:13:32 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_enemy(t_base *base)
{
	int			i;
	t_caractere	**enemy;

	enemy = NULL;
	enemy = (t_caractere **)malloc(sizeof(t_caractere *) * (NBR_OF_ENEMY + 1));
	if (!enemy)
		return (INIT_ALLOC);
	enemy[NBR_OF_ENEMY] = NULL;
	i = -1;
	while (++i < NBR_OF_ENEMY)
	{
		enemy[i] = (t_caractere *)malloc(sizeof(t_caractere) * 1);
		if (!enemy[i])
			return (INIT_ALLOC);
		ft_bzero(enemy[i], sizeof(t_caractere));
		//if (ft_input_monser(enemy[i]), i)
		//	return (INIT_MONSTER);
	}
	base->caractere = enemy;
	return (0);
}
