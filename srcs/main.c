/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:28:50 by stissera          #+#    #+#             */
/*   Updated: 2022/11/03 17:16:45 by stissera         ###   ########.fr       */
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
		base.window->mlx = mlx_init(SCREEN_X, SCREEN_Y, GAME_NAME, true);
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
