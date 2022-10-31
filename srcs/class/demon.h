/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:32:11 by stissera          #+#    #+#             */
/*   Updated: 2022/10/29 17:13:36 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef DEMON
#define DEMON

enemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 4;
enemy.rotate = 8; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "DEMON";
enemy.speed = 0.15;
enemy.health = 160;
enemy.attack = 34;
enemy.a_type = 0; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 88;
enemy.view = 80; // Distance of view

enemy.walk = 6;
enemy.w[0] = "SARGAx.xpm";
enemy.w[1] = "SARGBx.xpm";
enemy.w[2] = "SARGCx.xpm";
enemy.w[3] = "SARGDx.xpm";
enemy.w[4] = "SARGCx.xpm";
enemy.w[5] = "SARGBx.xpm";

enemy.fire = 4;
enemy.f[0] = "SARGEx.xpm";
enemy.f[1] = "SARGFx.xpm";
enemy.f[2] = "SARGGx.xpm";
enemy.f[3] = "SARGHx.xpm";

enemy.hit = 0;

enemy.death = 6;
enemy.d[0] = "SARGI0.xpm";
enemy.d[1] = "SARGJ0.xpm";
enemy.d[2] = "SARGK0.xpm";
enemy.d[3] = "SARGL0.xpm";
enemy.d[4] = "SARGM0.xpm";
enemy.d[4] = "SARGN0.xpm";


enemy.explose = 0;

#endif
