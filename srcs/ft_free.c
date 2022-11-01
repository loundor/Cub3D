/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:44:22 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 10:50:34 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_free_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (0);
}

int ft_free_int(int *nbr)
{
	if (nbr)
		free(nbr);
	nbr = 0;
	return (0);
}

int ft_free_tab(char **tab)
{
	size_t	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
	return (0);
}

int ft_free_tab_int(int **tab)
{
	size_t	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			free(tab[i]);
		free(tab);
		tab = 0;
	}
	return (0);
}

int	ft_free_base(t_base *base)
{
	int i;

	i = -1;
	if (base->player->start_position)
		free(base->player->start_position);
	ft_free_window(base->window);
	while (base->caractere && base->caractere[++i] != NULL)
		ft_free_caractere(base->caractere[i]);
	i = -1;
	while (base->items && base->items[++i] != NULL)
		ft_free_items(base->items[i]);
	i = -1;
	while (base->guns && base->guns[++i] != NULL)
		ft_free_guns(base->guns[i]);
	i = -1;
	while (base->ammo && base->ammo[++i] != NULL)
		ft_free_ammo(base->ammo[i]);
	ft_free_map(base->map);
	ft_free_root_base(base);
	base = NULL;
	return (0);
}

int ft_free_root_base(t_base *base)
{
	free(base->player);
	free(base->window);
	free(base->caractere);
	free(base->items);
	free(base->guns);
	free(base->ammo);
	free(base->map);
	return (0);
}

int ft_free_window(t_window *win)
{
	if (win->addr)
		ft_free_str(win->addr);
	if (win->screen)
		ft_free_str(win->screen);
	if (win->server)
		ft_free_str(win->server);
	if (win->win_id)
		ft_free_str(win->win_id);
	return (0);
}

int ft_free_caractere(t_caractere *car)
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

int ft_free_car_sprite(t_sprite *sprite)
{
	ft_free_tab(sprite->w_img); // [rotation][number of img]
	ft_free_tab_int(sprite->wx_decal);
	ft_free_tab_int(sprite->wy_decal);
	ft_free_tab(sprite->f_img); // [rotation][number]
	ft_free_tab_int(sprite->fx_decal);
	ft_free_tab_int(sprite->fy_decal);
	ft_free_tab(sprite->h_img); // [rotation][number]
	ft_free_tab_int(sprite->hx_decal);
	ft_free_tab_int(sprite->hy_decal);
	ft_free_str(sprite->d_img); // [rotation][number]
	ft_free_str(sprite->e_img);
	return (0);
}

int ft_free_items(t_items *items)
{
	ft_free_str(items->name);
	ft_free_tab((char **)items->sprite);
	ft_free_int(items->decal_x);
	ft_free_int(items->decal_y);
	free(items);
	return (0);
}

int ft_free_guns(t_guns *guns)
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

int ft_free_ammo(t_ammo *ammo)
{
	ft_free_str(ammo->name);
	ft_free_str(ammo->sprite);
	free(ammo);
	return (0);
}

int ft_free_map(t_map *map)
{
	ft_free_tab_int(map->map);
	ft_free_str(map->texture_n);
	ft_free_str(map->texture_s);
	ft_free_str(map->texture_e);
	ft_free_str(map->texture_w);
	ft_free_str(map->texture_f);
	ft_free_str(map->texture_c);
	return(0);
}