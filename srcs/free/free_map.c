/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:04:54 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 23:45:14 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free_map(t_map *map)
{
	ft_free_tab(map->map);
	ft_free_str(map->texture_n);
	ft_free_str(map->texture_s);
	ft_free_str(map->texture_e);
	ft_free_str(map->texture_w);
	ft_free_str(map->texture_f);
	ft_free_str(map->texture_c);
	return (0);
}
