/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:28:50 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 10:32:36 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_print_debug(t_base *base)
{
	int	y;
	int	x;

	y = -1;
	printf(DARKAMGENTA "Map size: " DARKRED "%d - %d\n"RST,
		base->map->size_x, base->map->size_y);
	while (base->map->map[++y])
	{
		x = -1;
		while (base->map->map[y][++x])
		{
			if (base->player->pos_x == x && base->player->pos_y == y)
				printf(BK_DARKBLUE "P"BK_RST);
			else
				printf(BK_DARKRED WHITE "%c"BK_RST RST, base->map->map[y][x]);
		}
		printf("\n");
	}
	return ;
}

int	main(int ac, char **av)
{
	t_base	base;

	if (ac != 2)
		return (1 + (0 * ft_error(ARG)));
	if (ft_file_name(av[1]))
		return (1 + (0 * write(1, "Error file name! Need .cub\n", 27)));
	ft_get_struct(&base);
	if (ft_s_player(&base) || ft_s_enemy(&base)
		|| ft_s_guns(&base) || ft_s_ammo(&base) || ft_s_items(&base)
		|| ft_s_map(&base) || ft_s_window(&base))
		return (1 + (0 * ft_error(INIT_BASE) * ft_free_base(&base)));
	if (ft_import_map (av[1], &base))
		return (1 + (0 * ft_error(MAP_ERROR) * ft_free_base(&base)));
	ft_print_debug(&base);
	ft_free_base(&base);
	return (0);
}

int	ft_file_name(char *file)
{
	int	i;

	i = 0;
	while (file && file[i])
		i++;
	if (ft_strncmp(&file[i - 4], ".cub", 5))
		return (1);
	return (0);
}

int	ft_error(int value)
{
	if (value == 1)
		ft_putstr_fd("Bad arguments!\n", 1);
	else if (value == 2)
		ft_putstr_fd("Initialisation error!\n", 1);
	else if (value == 4)
		ft_putstr_fd("Initialisation map error!\n", 1);
	else if (value == 8)
		ft_putstr_fd("Initialisation monsters error!\n", 1);
	else if (value == 0x10)
		ft_putstr_fd("Initialisation guns error!\n", 1);
	else if (value == 0x20)
		ft_putstr_fd("Initialisation ammo error!\n", 1);
	else if (value == 0x40)
		ft_putstr_fd("Initialisation items error!\n", 1);
	else if (value == 0x80)
		ft_putstr_fd("Initialisation screen error!\n", 1);
	else if (value == 0xFF)
		ft_putstr_fd("Malloc error!\n", 1);
	else if (value == 0xA0)
		ft_putstr_fd("Sprite file don't exist or bad access!\n", 1);
	else if (value == 0xAA)
		ft_putstr_fd("Bad argument color!\n", 1);
	else if (value == 0xB0)
		ft_putstr_fd("Error: Multiple player in card. Please fix for only one.\n", 1);
	else
		ft_putstr_fd("Exit\n", 1);
	return (0);
}
