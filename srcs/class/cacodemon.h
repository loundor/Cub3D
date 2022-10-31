/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cacodemon.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:44:30 by stissera          #+#    #+#             */
/*   Updated: 2022/10/30 21:16:31 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef CACODEMON
#define CACODEMON

enemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 5;
enemy.rotate = 5; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "CACODEMON";
enemy.speed = 0.13;
enemy.health = 240;
enemy.attack = 41;
enemy.a_type = 3; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 45;
enemy.view = 320; // Distance of view

enemy.walk = 1;
enemy.w[0][r][0] = "HEADAr.xpm";

enemy.fire = 5;
enemy.f[0][r][0] = "HEADBr.xpm";
enemy.f[1][r][0] = "HEADCr.xpm";
enemy.f[2][r][0] = "HEADDr.xpm";
enemy.f[3][r][0] = enemy.f[2][r][0];
enemy.f[4][r][0] = enemy.f[1][r][0];

enemy.hit = 2;
enemy.h[0][r][0] = "HEADEr.xpm";
enemy.h[1][r][0] = "HEADFr.xpm";

enemy.death = 6;
enemy.d[0][0] = "HEADG0.xpm";
enemy.d[1][0] = "HEADH0.xpm";
enemy.d[2][0] = "HEADI0.xpm";
enemy.d[3][0] = "HEADJ0.xpm";
enemy.d[4][0] = "HEADK0.xpm";
enemy.d[5][0] = "HEADL0.xpm";

enemy.explose = 0;

#endif
