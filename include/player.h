/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:52:23 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 12:24:56 by stissera         ###   ########.fr       */
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
	int			run;
	int			fire;
	int			reload;
	int			switch_gun;
	int			jump;
	int			crouch;
	float		angle;
	float		pos_x;
	float		delta_x;
	float		pos_y;
	float		delta_y;
	float		pos_z;
	float		delta_z;
	char		start_position;
	int			c_kill;
	int			c_fire;
	long long	c_time;
} t_player;

#endif
