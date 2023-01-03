/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:39:23 by stissera          #+#    #+#             */
/*   Updated: 2023/01/03 18:16:16 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	g;
	t_map	map;
	t_pos	player;

	ft_init_struct(&g, &map, &player);
	ft_get_struct(&g);
	if (ac != 2)
		return (1 + (0 * ft_error(ARG)));
	if (ft_file_name(av[1]))
		return (1 + (0 * write(1, "Error file name! Need .cub\n", 27)));
	window_init(&g);
	if (ft_import_map (av[1], &g))
		return (1 + (0 * ft_error(MAP_ERROR)));
	ft_print_struct(&g);
	mlx_loop_hook(g.mlx, &hook, &g);
	mlx_loop(g.mlx);
	//ft_free_base(&g);
	return (0);
}

int	ft_init_struct(t_game *g, t_map *map, t_pos *player)
{
	player->positioned = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->map = NULL;
	g->player = player;
	g->map = map;
	return (0);
}

void	window_init(t_game *g)
{
	g->mlx = mlx_init(SCREEN_X, SCREEN_Y, NAME, true);
	if (!g->mlx)
		exit (1);// + ft_free_window(g->mlx));
	g->img = mlx_new_image(g->mlx, SCREEN_X, SCREEN_Y);
	mlx_image_to_window(g->mlx, g->img, 0, 0);
	mlx_put_string(g->mlx, "LOADING...", 200, 200);
	g->scale = SCREEN_X / SCALE;
	//if (ft_strart_screen(&g, av))
	//	return (1);
}

void	ft_print_struct(t_game *g)
{
	int	i;
	int	e;

	printf("	mlx: %p\n\
	win: %p\n\
	scale: %f\n\
	player x:%f - y: %f\n\
	player angle: %f\n\
	player pos: %c\n",
		g->mlx, g->win, g->scale, g->player->x, g->player->y,
		g->player->angle, g->player->positioned);
	printf("map x: %d - y: %d\n", g->map->size_x, g->map->size_y);
	i = -1;
	while (g->map->map[++i])
	{
		e = -1;
		while (g->map->map[i][++e])
			printf("%c ", g->map->map[i][e]);
		printf("\n");
	}
	printf("map x: %d - y: %d\n", g->map->size_x, g->map->size_y);
}
