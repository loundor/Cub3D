/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:57 by stissera          #+#    #+#             */
/*   Updated: 2023/01/09 10:02:34 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_set_map(t_game *g, char *line, int onmap)
{
	size_t	i;

	if (!onmap)
	{
		i = 0;
		while (line && ft_isspace(line[i]))
			i++;
		if (!line[i])
			return (0);
		if ((!ft_strncmp(&line[i], "NO ", 3) || !ft_strncmp(&line[i], "SO ", 3)
				|| !ft_strncmp(&line[i], "WE ", 3)
				|| !ft_strncmp(&line[i], "EA ", 3)
				|| !ft_strncmp(&line[i], "F ", 2)
				|| !ft_strncmp(&line[i], "C ", 2)))
			return (ft_map_insert_param(&line[i], g));
	}
	return (ft_map_create(line, g->map));
}

static int	ft_read_line_map(char *buffer, char **line, int *w_map, t_game *g)
{
	if (*buffer != '\n')
	{
		if (*line)
			*line = ft_strjoin(*line, buffer) + ft_free_str(*line);
		else
			*line = ft_strdup(buffer);
	}
	else if (*line)
	{
		*w_map = *w_map + ft_set_map(g, *line, *w_map) + ft_free_str(*line);
		if (*w_map == -1)
			return (1);
		*line = NULL;
	}
	else if (!*line && (*buffer == '\n') && *w_map > 0)
		return (1);
	return (0);
}

int	ft_import_map(char *file, t_game *g)
{
	int		fd;
	char	buffer[2];
	char	*line;
	int		w_map;

	line = NULL;
	w_map = 0;
	ft_bzero(buffer, 2);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1 + (0 * write(1, "Can't found the map file!\n", 26)));
	while (read(fd, &buffer, 1) && w_map != -1)
		if (ft_read_line_map(buffer, &line, &w_map, g))
			return (4 + (0 * write(1, "Error: Space line in map.\n", 26)));
	if (line && ft_read_line_map("\n", &line, &w_map, g))
		return (4 + (0 * write(1, "Error: Space line in map.\n", 26)));
	if (w_map < 3)
		return (MAP_ERROR);
	return (0);
}
