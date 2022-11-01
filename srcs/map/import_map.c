/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:25:43 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 00:46:28 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_map_create(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i > 0)
	{
		if (i > map->size_x)
			map->size_x = i;
		map->size_y++;
		if (map->map || ft_map_first(map, line)) // ft_map_create return 0 if ok otherwise exit in function
			if (ft_realloc_map(map, line))
				exit(1 + (0 * ft_error(INIT_ALLOC)
						* ft_free_base(ft_get_struct(0))));
		return (1);
	}
	return (0);
}

int	ft_map_first(t_map *map, char *line)
{
	int		c;
	char	**create;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create)
		exit(1 + (0 * ft_error(INIT_ALLOC)
				* ft_free_base(ft_get_struct(0))));
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	create[0] = (char *)malloc(sizeof(char) * (map->size_x + 1));
	if (!create[0])
		exit(1 + (0 * ft_error(INIT_ALLOC)
				* ft_free_base(ft_get_struct(0))));
	ft_bzero(create[0], map->size_x + 1);
	c = -1;
	while (*line)
		create[0][++c] = *line++;
	map->map = create;
	return (0);
}

int	ft_realloc_map(t_map *map, char *line)
{
	int		l;
	int		c;
	char	**create;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create)
		exit(1 + (0 * ft_error(INIT_ALLOC)
				* ft_free_base(ft_get_struct(0))));
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	l = -1;
	while (++l < map->size_y)
	{
		create[l] = (char *)malloc(sizeof(char) * (map->size_x) + 1);
		if (!create[l])
			exit(1 + (0 * ft_error(INIT_ALLOC)
					* ft_free_base(ft_get_struct(0))));
		ft_bzero(create[l], map->size_x + 1);
		c = -1;
		while (l < map->size_y - 1 && map->map[l][++c])
			create[l][c] = map->map[l][c];
	}
	while (*line)
		create[l - 1][++c] = *line++; // search for player to put in player->startpos && remplace start position by 0;
	map->map = ft_free_tab(map->map) + create;
	return (0);
}
