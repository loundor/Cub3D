/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:28:50 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 02:12:00 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_base	base;

	if (ac != 2)
		return (1 + (0 * ft_error(ARG)));
	if (ft_file_name(av[1]))
		return (1 + (0 * write(1, "Error file name! Need .cub\n", 27)));
	if (ft_s_window(&base))
		return (1 + (0 * ft_error(MAP_ERROR)));
	else
	{
		base.window->mlx = mlx_init(SCREEN_X, SCREEN_Y, GAME_NAME, false);
		if (!base.window->mlx)
			return (1 + ft_free_window(base.window));
	}
	ft_get_struct(&base);
	if (ft_strart_screen(&base, av))
		return (1);
	mlx_terminate(base.window->mlx);
	ft_free_base(&base);
	return (0);
}

int	ft_strart_screen(t_base *base, char **av)
{
	mlx_loop_hook(base->window->mlx, &hook, base->window->mlx);
	if (ft_s_player(base) || ft_s_enemy(base) || ft_s_guns(base)
		|| ft_s_ammo(base) || ft_s_items(base) || ft_s_map(base))
		return (1 + (0 * ft_error(INIT_BASE) * ft_free_base(base)));
	if (ft_import_map (av[1], base))
		return (1 + (0 * ft_error(MAP_ERROR) * ft_free_base(base)));
	ft_draw_minimap(base);
	mlx_loop(base->window->mlx);
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
		ft_putstr_fd("Error: Multiple player in card.\n", 1);
	else
		ft_putstr_fd("Exit\n", 1);
	return (0);
}
