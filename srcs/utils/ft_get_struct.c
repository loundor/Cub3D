/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:25 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:17:36 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_base	*ft_get_struct(void *data)
{
	static int			reload;
	static t_base		*base;

	if (reload != 1)
	{
		base = (t_base *)data;
		reload = 1;
		return (0);
	}
	(void)data;
	return (base);
}
