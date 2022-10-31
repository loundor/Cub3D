/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caractere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:54:06 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 13:12:18 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARACTERE_H
#define CARACTERE_H

typedef struct s_sprite
{
	int			walk; // nbr img annimation
	char		**w_img; // [rotation][number of img]
	int			**wx_decal;
	int			**wy_decal;
	int 		fire;
	char		**f_img; // [rotation][number]
	int			**fx_decal;
	int			**fy_decal;
	int			hit;
	char		**h_img; // [rotation][number]
	int			**hx_decal;
	int			**hy_decal;
	int			death;
	char		*d_img; // [rotation][number]
	int			dx_decal;
	int			dy_decal;
	int			explose;
	char		*e_img;
	int			ex_decal;
	int			ey_decal;
} t_sprite;

typedef struct s_caractere
{
	int				id;
	char			*name;
	float			speed;
	int				health;
	int				ammo_type;
	int				attack;
	int				*a_type;
	int				fov;
	int				view;
	struct s_sprite	*sprite;
} t_caractere;

#endif
