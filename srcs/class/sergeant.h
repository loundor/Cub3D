/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sergeant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:24:50 by stissera          #+#    #+#             */
/*   Updated: 2022/10/29 17:13:34 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef SERGEANT
#define SERGEANT

enemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 2;
enemy.rotate = 5; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "SERGEANT";
enemy.speed = 0.1;
enemy.health = 90;
enemy.attack = 26;
enemy.a_type = 1; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 66;
enemy.view = 180; // Distance of view

enemy.walk = 6;
enemy.w[0] = "SPOSAx.xpm";
enemy.w[1] = "SPOSBx.xpm";
enemy.w[2] = "SPOSCx.xpm";
enemy.w[3] = "SPOSDx.xpm";
enemy.w[4] = "SPOSCx.xpm";
enemy.w[5] = "SPOSBx.xpm";

enemy.fire = 2;
enemy.f[0] = "SPOSEx.xpm";
enemy.f[1] = "SPOSFx.xpm";

enemy.hit = 1;
enemy.h[0] = "SPOSGx.xpm";

enemy.death = 5;
enemy.d[0] = "SPOSSH0.xpm";
enemy.d[1] = "SPOSSI0.xpm";
enemy.d[2] = "SPOSSJ0.xpm";
enemy.d[3] = "SPOSSK0.xpm";
enemy.d[4] = "SPOSSL0.xpm";

enemy.explose = 9;
enemy.e[0] = "SPOSM0.xpm";
enemy.e[1] = "SPOSN0.xpm";
enemy.e[2] = "SPOSO0.xpm";
enemy.e[3] = "SPOSP0.xpm";
enemy.e[4] = "SPOSQ0.xpm";
enemy.e[5] = "SPOSR0.xpm";
enemy.e[6] = "SPOSS0.xpm";
enemy.e[7] = "SPOST0.xpm";
enemy.e[8] = "SPOSU0.xpm";

#endif
