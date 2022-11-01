/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:05:26 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:05:52 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free_window(t_window *win)
{
	if (win->addr)
		ft_free_str(win->addr);
	if (win->screen)
		ft_free_str(win->screen);
	if (win->server)
		ft_free_str(win->server);
	if (win->win_id)
		ft_free_str(win->win_id);
	return (0);
}
