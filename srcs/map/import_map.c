/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:25:43 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 10:35:16 by stissera         ###   ########.fr       */
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
		if (map->map || ft_map_first(map, line, NULL))
			if (ft_realloc_map(map, line, NULL))
				exit(1 + (0 * ft_error(INIT_ALLOC)
						* ft_free_base(ft_get_struct(0))));
		return (1);
	}
	return (0);
}

int	ft_map_first(t_map *map, char *line, char **create)
{
	int		c;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create && ft_error(INIT_ALLOC))
		exit(1 + (0 * ft_free_base(ft_get_struct(0))));
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	create[0] = (char *)malloc(sizeof(char) * (map->size_x + 1));
	if (!create[0] && ft_error(INIT_ALLOC))
		exit(1 + (0 * ft_free_base(ft_get_struct(0))));
	ft_bzero(create[0], map->size_x + 1);
	ft_memset(create[0], '0', map->size_x);
	c = -1;
	while (*line)
	{
		if ((*line == ' ' || *line == 'N' || *line == 'S'
				|| *line == 'E' || *line == 'W') && line++)
		{
			create[0][++c] = '0';
			continue ;
		}
		create[0][++c] = *line++;
	}
	map->map = create;
	return (0);
}

int	ft_realloc_map(t_map *map, char *line, char **create)
{
	int		l;
	int		c;

	create = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!create && ft_error(INIT_ALLOC))
		exit(1 + (0 * ft_free_base(ft_get_struct(0))));
	ft_bzero(create, sizeof(char *) * (map->size_y + 1));
	l = -1;
	while (++l < map->size_y)
	{
		create[l] = (char *)malloc(sizeof(char) * (map->size_x) + 1);
		if (!create[l] && ft_error(INIT_ALLOC))
			exit(1 + (0 * ft_free_base(ft_get_struct(0))));
		ft_bzero(create[l], map->size_x + 1);
		if (l < map->size_y - 1)
			ft_memset(create[l], 48, map->size_x);
		c = -1;
		while (l < map->size_y - 1 && map->map[l][++c])
			create[l][c] = map->map[l][c];
	}
	ft_memset(create[--l], '0', map->size_x);
	while (*line)
		ft_input_line_map(&line, create, &l, &c);
	map->map = ft_free_tab(map->map) + create;
	return (0);
}

void	ft_input_line_map(char **line, char **create, int *l, int *c)
{
	t_base	*base;

	base = ft_get_struct(NULL);
	*c = *c + 1;
	if (**line == 'N' || **line == 'S' || **line == 'E' || **line == 'W')
	{
		create[*l][*c] = '0';
		if (base->player->start_position != 0 && !ft_error(BAD_START))
			exit(1 + (0 * ft_free_base(ft_get_struct(0))));
		base->player->start_position = *line[0]++;
		base->player->pos_x = *c;
		base->player->pos_y = *l;
	}
	else if (**line == ' ' && *line[0]++)
		create[*l][*c] = '0';
	else
		create[*l][*c] = *line[0]++;
	return ;
}
