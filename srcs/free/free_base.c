/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:06:12 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:13:46 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free_base(t_base *base)
{
	int	i;

	i = -1;
	ft_free_window(base->window);
	while (base->caractere && base->caractere[++i] != NULL)
		ft_free_caractere(base->caractere[i]);
	i = -1;
	while (base->items && base->items[++i] != NULL)
		ft_free_items(base->items[i]);
	i = -1;
	while (base->guns && base->guns[++i] != NULL)
		ft_free_guns(base->guns[i]);
	i = -1;
	while (base->ammo && base->ammo[++i] != NULL)
		ft_free_ammo(base->ammo[i]);
	ft_free_map(base->map);
	ft_free_root_base(base);
	base = NULL;
	return (0);
}

int	ft_free_root_base(t_base *base)
{
	free(base->player);
	free(base->window);
	free(base->caractere);
	free(base->items);
	free(base->guns);
	free(base->ammo);
	free(base->map);
	return (0);
}
