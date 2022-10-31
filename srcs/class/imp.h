/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:54:01 by stissera          #+#    #+#             */
/*   Updated: 2022/10/29 17:13:31 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef IMP
#define IMP

ennemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 3;
enemy.rotate = 5; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "IMP";
enemy.speed = 0.1;
enemy.health = 90;
enemy.attack = 22;
enemy.a_type = 2; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 66;
enemy.view = 180; // Distance of view

enemy.walk = 6;
enemy.w[0] = "TROOAx.xpm";
enemy.w[1] = "TROOBx.xpm";
enemy.w[2] = "TROOCx.xpm";
enemy.w[3] = "TROODx.xpm";
enemy.w[4] = "TROOCx.xpm";
enemy.w[5] = "TROOBx.xpm";

enemy.fire = 3;
enemy.f[0] = "TROOEx.xpm";
enemy.f[1] = "TROOFx.xpm";
enemy.f[2] = "TROOGx.xpm";

enemy.hit = 1;
enemy.h[0] = "TROOHx.xpm";

enemy.death = 5;
enemy.d[0] = "TROOI0.xpm";
enemy.d[1] = "POSSJ0.xpm";
enemy.d[2] = "POSSK0.xpm";
enemy.d[3] = "POSSL0.xpm";
enemy.d[4] = "POSSM0.xpm";

enemy.explose = 8;
enemy.e[0] = "TROON0.xpm";
enemy.e[1] = "TROOO0.xpm";
enemy.e[2] = "TROOP0.xpm";
enemy.e[3] = "TROOQ0.xpm";
enemy.e[4] = "TROOR0.xpm";
enemy.e[5] = "TROOS0.xpm";
enemy.e[6] = "TROOT0.xpm";
enemy.e[7] = "TROOU0.xpm";

#endif
