/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:39:23 by stissera          #+#    #+#             */
/*   Updated: 2023/01/03 00:21:05 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	g;
	t_map	map;
	map.size_x = 0;
	map.size_y = 0;
	g.map = &map;
	
	if (ac != 2)
		return (1 + (0 * ft_error(ARG)));
	if (ft_file_name(av[1]))
		return (1 + (0 * write(1, "Error file name! Need .cub\n", 27)));
//	if (ft_s_window(&g))
//		return (1 + (0 * ft_error(MAP_ERROR)));
//	else
		window_init(&g);
	//if (ft_strart_screen(&g, av))
	//	return (1);
	if (ft_import_map (av[1], &g))
		return (1 + (0 * ft_error(MAP_ERROR)));
	ft_get_struct(&g);

	mlx_loop_hook(g.mlx, &hook, &g.mlx);
	mlx_loop(g.mlx);
	//ft_free_base(&g);
	return (0);
}

void	window_init(t_game *g)
{
	g->mlx = mlx_init(SCREEN_X, SCREEN_Y, NAME, true);
	//g->win = mlx_new_window(g->mlx, SCREEN_X, SCREEN_Y, NAME);
	g->img = mlx_new_image(g->mlx, SCREEN_X, SCREEN_Y);
	g->scale = SCREEN_X / SCALE;
	if (!g->mlx)
		exit (1);// + ft_free_window(g->mlx));
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
