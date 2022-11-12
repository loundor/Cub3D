/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:06:35 by stissera          #+#    #+#             */
/*   Updated: 2022/11/05 16:32:01 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	ft_degtorad(float deg)
{
	return (deg * M_PI / 180);
}

float	ft_radtodeg(float rad)
{
	return (rad * (180 / M_PI));
}
