/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:53:03 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 19:04:11 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window
{
	mlx_t		*mlx;
	void		*server;
	int			bpp;
	int			line_lenght;
	int			endian;
	char		*addr;
	void		*screen;
}	t_window;

#endif
