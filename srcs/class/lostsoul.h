/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lostsoul.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:05:14 by stissera          #+#    #+#             */
/*   Updated: 2022/10/30 11:11:21 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*				In file name, the minus "x" is the angle-rotation			  */
/*		(beetween 1 and 8 include) where 6 to 8 is a mirror of 4 to 2		  */
/* ************************************************************************** */

#ifndef LOSTSOUL
#define LOSTSOUL

enemy.folder = "../../DOOMEXP/IMG/CARACTERE/"
enemy.id = 6;
enemy.rotate = 5; // number of rotation img (5 means 6 7 8 is a mirror of 2 3 4)
enemy.name = "LOSTSOUL";
enemy.speed = 0.8;
enemy.health = 60;
enemy.attack = 41;
enemy.a_type = 4; // 0 = head to head 1 = bullet 2=red fire 3=violet fire 4 = self 5=green fire 6=rocket
enemy.fov = 72;
enemy.view = 200; // Distance of view

enemy.walk = 2;
// [a][r][x][y]
// a = file; r = rotation angle %45; x = decal x; y = decal
enemy.w[0][r][0] = "SKULAr.xpm"; // File name
enemy.w[0][r][1] = ; // decal x
enemy.w[0][r][2] = ; // decal y
enemy.w[1][r][0] = "SKULBr.xpm";
enemy.w[1][r][1] = ;
enemy.w[0][r][2] = ;

enemy.fire = 2;
enemy.f[0][r][0] = "SKULCr.xpm";
enemy.f[0][r][1] = ;
enemy.f[0][r][2] = ;
enemy.f[1][r][0] = "SKULDr.xpm";
enemy.f[1][r][1] = ;
enemy.f[1][r][2] = ;

enemy.hit = 1;
enemy.h[0][r][0] = "SKULEr.xpm";
enemy.h[0][r][1] = ;
enemy.h[0][r][2] = ;

enemy.death = 6;
enemy.d[0][0] = "SKULF0.xpm";
enemy.d[0][1] = ;
enemy.d[0][2] = ;
enemy.d[1][0] = "SKULG0.xpm";
enemy.d[1][1] = ;
enemy.d[1][2] = ;
enemy.d[2][0] = "SKULH0.xpm";
enemy.d[2][1] = ;
enemy.d[2][2] = ;
enemy.d[3][0] = "SKULI0.xpm";
enemy.d[3][1] = ;
enemy.d[3][2] = ;
enemy.d[4][0] = "SKULJ0.xpm";
enemy.d[4][1] = ;
enemy.d[4][2] = ;
enemy.d[5][0] = "SKULK0.xpm";
enemy.d[5][1] = ;
enemy.d[5][2] = ;

enemy.explose = 0;

#endif