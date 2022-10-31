/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:34:36 by stissera          #+#    #+#             */
/*   Updated: 2022/10/29 17:13:23 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

ennemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 1;
enemy.rotate = 5; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "ZOMBIE";
enemy.speed = 0.1;
enemy.health = 60;
enemy.attack = 12;
enemy.a_type = 1; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 66;
enemy.view = 180; // Distance of view

enemy.walk = 6;
enemy.w[0] = "POSSAx.xpm";
enemy.w[1] = "POSSBx.xpm";
enemy.w[2] = "POSSCx.xpm";
enemy.w[3] = "POSSDx.xpm";
enemy.w[4] = "POSSCx.xpm";
enemy.w[5] = "POSSBx.xpm";

enemy.fire = 2;
enemy.f[0] = "POSSEx.xpm";
enemy.f[1] = "POSSFx.xpm";

enemy.hit = 1;
enemy.h[0] = "POSSGx.xpm";

enemy.death = 5;
enemy.d[0] = "POSSH0.xpm";
enemy.d[1] = "POSSI0.xpm";
enemy.d[2] = "POSSJ0.xpm";
enemy.d[3] = "POSSK0.xpm";
enemy.d[4] = "POSSL0.xpm";

enemy.explose = 9;
enemy.e[0] = "POSSM0.xpm";
enemy.e[1] = "POSSN0.xpm";
enemy.e[2] = "POSSO0.xpm";
enemy.e[3] = "POSSP0.xpm";
enemy.e[4] = "POSSQ0.xpm";
enemy.e[5] = "POSSR0.xpm";
enemy.e[6] = "POSSS0.xpm";
enemy.e[7] = "POSST0.xpm";
enemy.e[8] = "POSSU0.xpm";

#endif
