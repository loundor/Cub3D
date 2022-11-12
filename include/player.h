/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:52:23 by stissera          #+#    #+#             */
/*   Updated: 2022/11/10 22:09:46 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

typedef struct s_player
{
	int			status;
	int			life;
	int			armor;
	int			guns[8];
	int			ammo[4];
	int			god;
	int			hit;
	int			berserk;
	int			visibility;
	int			invisibility;
	int			key[6];
	int			fire;
	int			reload;
	int			switch_gun;
	int			jump;
	int			crouch;

	int			c_kill;
	int			c_fire;
	long long	c_time;

	char		start_position;
	int			speed;
	int			r_speed;
	int			fov;
	int			angle;
	float		pos_x;
	float		pos_y;
	float		delta_x;
	float		delta_y;
	float		tan;

} t_player;

#endif
