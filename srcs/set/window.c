/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:16:17 by stissera          #+#    #+#             */
/*   Updated: 2022/11/09 15:27:35 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_s_window(t_base *base)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window) * 1);
	if (!window)
		return (INIT_ALLOC);
	ft_bzero(window, sizeof(t_window));
	window->scale = SCREEN_X / SCALE;
	base->window = window;
	return (0);
}
