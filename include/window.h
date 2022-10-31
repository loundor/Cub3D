/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:53:03 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 15:12:26 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

typedef struct s_window
{
	void 	*server;
	void	*win_id;
	int		size_x;
	int 	size_y;
	int		bpp;
	int		line_lenght;
	int		endian;
	char	*addr;
	void	*screen;
} t_window;

#endif
