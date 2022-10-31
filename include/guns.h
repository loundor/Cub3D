/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:55:32 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 14:52:55 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUNS_H
#define GUNS_H

typedef struct s_guns
{
	int		id;
	char	*name;
	int		pain;
	int		type_ammo;
	int		ammo_fire; // min ammo need for fire and nbr ammo used
	float	reload; // time to reload
	int		play_a;
	void	**p_sprite;
	int		*p_decal_x;
	int		*p_decal_y;
	int		attack_a;
	void	**a_sprite;
	int		*a_decal_x;
	int		*a_decal_y;
	int		fire_a;
	void	**f_sprite;
	int		*f_decal_x;
	int		*f_decal_y;
	int		end_a;
	void	**e_sprite;
	int		*e_decal_x;
	int		*e_decal_y;
}	t_guns;
#endif
