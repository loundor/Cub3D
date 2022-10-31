/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:56:02 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 14:24:19 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMMO_H
#define AMMO_H

typedef struct s_ammo
{
	int		id;
	char	*name;
	void	*sprite;
	int		decal_x;
	int		decal_y;
	int		type;
	int		add;
}	t_ammo;

#endif
