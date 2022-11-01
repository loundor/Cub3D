/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:39 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:04:26 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free_caractere(t_caractere *car)
{
	if (car->name && car->name != NULL)
		ft_free_str(car->name);
	if (car->a_type)
		ft_free_int(car->a_type);
	if (car->sprite)
		ft_free_car_sprite(car->sprite);
	car->sprite = NULL;
	free(car);
	return (0);
}

int	ft_free_car_sprite(t_sprite *sprite)
{
	ft_free_tab(sprite->w_img);
	ft_free_tab_int(sprite->wx_decal);
	ft_free_tab_int(sprite->wy_decal);
	ft_free_tab(sprite->f_img);
	ft_free_tab_int(sprite->fx_decal);
	ft_free_tab_int(sprite->fy_decal);
	ft_free_tab(sprite->h_img);
	ft_free_tab_int(sprite->hx_decal);
	ft_free_tab_int(sprite->hy_decal);
	ft_free_str(sprite->d_img);
	ft_free_str(sprite->e_img);
	return (0);
}

int	ft_free_items(t_items *items)
{
	ft_free_str(items->name);
	ft_free_tab((char **)items->sprite);
	ft_free_int(items->decal_x);
	ft_free_int(items->decal_y);
	free(items);
	return (0);
}

int	ft_free_guns(t_guns *guns)
{
	ft_free_str(guns->name);
	ft_free_tab((char **)guns->p_sprite);
	ft_free_int(guns->p_decal_x);
	ft_free_int(guns->p_decal_y);
	ft_free_tab((char **)guns->a_sprite);
	ft_free_int(guns->a_decal_x);
	ft_free_int(guns->a_decal_y);
	ft_free_tab((char **)guns->f_sprite);
	ft_free_int(guns->f_decal_x);
	ft_free_int(guns->f_decal_y);
	ft_free_tab((char **)guns->e_sprite);
	ft_free_int(guns->e_decal_x);
	ft_free_int(guns->e_decal_y);
	free(guns);
	return (0);
}

int	ft_free_ammo(t_ammo *ammo)
{
	ft_free_str(ammo->name);
	ft_free_str(ammo->sprite);
	free(ammo);
	return (0);
}
