/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:56:31 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 21:20:24 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H


/* ************************************************************************** */
/* 				In int floor, ceiling, wall_x : 0 = RGB - 1 = file			  */
/*		 If 0, texture_x must be RGBA coded on 32 bits (4 block of 8bits)	  */
/*	Ex if 0:		 R			  G			   B			A				  */
/*					255			 35			  155			0				  */
/*				 1111 1111    0010 0011    0110 1101    0000 0000			  */
/* ************************************************************************** */

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		**map;
	int		wall_n;
	void	*texture_n;
	int		wall_s;
	void	*texture_s;
	int		wall_e;
	void	*texture_e;
	int		wall_w;
	void	*texture_w;
	int		floor;
	void	*texture_f;
	int		ceiling;
	void	*texture_c;
}	t_map;

#endif
