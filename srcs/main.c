/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:28:50 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 10:49:26 by stissera         ###   ########.fr       */
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
	ft_get_struct(&base);
	if (ft_s_player(&base) || ft_s_enemy(&base)
		|| ft_s_guns(&base) || ft_s_ammo(&base) || ft_s_items(&base)
		|| ft_s_map(&base) || ft_s_window(&base))
		return (1 + (0 * ft_error(INIT_BASE) * ft_free_base(&base)));
	if (ft_import_map (av[1], &base))
		return (1 + (0 * ft_error(MAP_ERROR) * ft_free_base(&base)));
	ft_free_base(&base);
	return (0);
}

t_base	*ft_get_struct(void *data)
{
	static int			reload;
	static t_base		*base;

	if (reload != 1)
	{
		base = (t_base *)base;
		reload = 1;
		return (0);
	}
	(void)data;
	return (base);
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
		ft_putstr_fd("File don't exist or bad access!\n", 1);
	else if (value == 0xAA)
		ft_putstr_fd("Bad argument color!\n", 1);
	else
		ft_putstr_fd("Exit\n", 1);
	return (0);
}

int	ft_s_player(t_base *base)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player) * 1);
	if (!player)
		return (INIT_ALLOC);
	ft_bzero(player, sizeof(t_player));
	base->player = player;
	return (0);
}

int	ft_s_enemy(t_base *base)
{
	int			i;
	t_caractere	**enemy;

	enemy = NULL;
	enemy = (t_caractere **)malloc(sizeof(t_caractere *) * (NBR_OF_ENEMY + 1));
	if (!enemy)
		return (INIT_ALLOC);
	enemy[NBR_OF_ENEMY] = NULL;
	i = -1;
	while (++i < NBR_OF_ENEMY)
	{
		enemy[i] = (t_caractere *)malloc(sizeof(t_caractere) * 1);
		if (!enemy[i])
			return (INIT_ALLOC);
		ft_bzero(enemy[i], sizeof(t_caractere));
		//if (ft_input_monser(enemy[i]), i)
		//	return (INIT_MONSTER);
	}
	base->caractere = enemy;
	return (0);
}

int	ft_s_ammo(t_base *base)
{
	int		i;
	t_ammo	**ammo;

	ammo = NULL;
	ammo = (t_ammo **)malloc(sizeof(t_ammo *) * (NBR_OF_AMMO + 1));
	if (!ammo)
		return (INIT_ALLOC);
	ammo[NBR_OF_AMMO] = NULL;
	i = -1;
	while (++i < NBR_OF_AMMO)
	{
		ammo[i] = (t_ammo *)malloc(sizeof(t_ammo) * 1);
		if (!ammo[i])
			return (INIT_ALLOC);
		ft_bzero(ammo[i], sizeof(t_ammo));
		//if (ft_input_ammo(ammo[i]), i)
		//	return (INIT_AMMO);
	}
	base->ammo = ammo;
	return (0);
}

int	ft_s_items(t_base *base)
{
	int		i;
	t_items	**items;

	items = NULL;
	items = (t_items **)malloc(sizeof(t_items *) * (NBR_OF_ITEMS + 1));
	if (!items)
		return (INIT_ALLOC);
	items[NBR_OF_ITEMS] = NULL;
	i = -1;
	while (++i < NBR_OF_ITEMS)
	{
		items[i] = (t_items *)malloc(sizeof(t_items) * 1);
		if (!items[i])
			return (INIT_ALLOC);
		ft_bzero(items[i], sizeof(t_items));
		//if (ft_input_items(items[i]), i)
		//	return (INIT_ITEMS);
	}
	base->items = items;
	return (0);
}

int	ft_s_guns(t_base *base)
{
	int		i;
	t_guns	**guns;

	guns = NULL;
	guns = (t_guns **)malloc(sizeof(t_guns *) * (NBR_OF_GUNS + 1));
	if (!guns)
		return (INIT_ALLOC);
	guns[NBR_OF_GUNS] = NULL;
	i = -1;
	while (++i < NBR_OF_GUNS)
	{
		guns[i] = (t_guns *)malloc(sizeof(t_guns) * 1);
		if (!guns[i])
			return (INIT_ALLOC);
		ft_bzero(guns[i], sizeof(t_guns));
		//if (ft_input_guns(guns[i]), i)
		//	return (INIT_GUNS);
	}
	base->guns = guns;
	return (0);
}

int	ft_s_map(t_base *base)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return (INIT_ALLOC);
	ft_bzero(map, sizeof(t_map));
	base->map = map;
	return (0);
}

int	ft_s_window(t_base *base)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window) * 1);
	if (!window)
		return (INIT_ALLOC);
	ft_bzero(window, sizeof(t_window));
	window->size_x = SCREEN_X;
	window->size_y = SCREEN_Y;
	base->window = window;
	return (0);
}

int	ft_import_map(char *file, t_base *base)
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
		if (ft_read_line_map(buffer, &line, &w_map, base))
			return (4 + (0 * write(1, "Error: Space line in map.\n", 26)));
	if (w_map < 3)
		return (MAP_ERROR);
	return (0);
}

int	ft_read_line_map(char *buffer, char **line, int *w_map, t_base *base)
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
		*w_map = *w_map + ft_set_map(base, *line, *w_map) + ft_free_str(*line);
		if (*w_map == -1)
			return (1);
		*line = NULL;
	}
	else if (!*line && *buffer == '\n' && *w_map > 0)
		return (1);
	return (0);
}

int	ft_set_map(t_base *base, char *line, int onmap)
{
	size_t	i;

	(void)base;
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
			return (ft_map_insert_param(&line[i], base));
	}
	// return (ft_map_create(&line));
	puts(line);
	return (1);
}

int	ft_map_insert_param(char *line, t_base *base)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		line += 3;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_n, &base->map->wall_n);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		line += 3;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_s, &base->map->wall_s);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		line += 3;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_w, &base->map->wall_w);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		line += 3;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_e, &base->map->wall_e);
	}
	else if (!ft_strncmp(line, "F ", 2))
	{
		line += 2;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_f, &base->map->floor);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		line += 2;
		while (line && *line == ' ')
			line++;
		if (*line)
			ft_putarg_in(line, &base->map->texture_c, &base->map->ceiling);
	}
	else
		return (-1 + (0 * write(1, "Invalid argurment in map file!\n", 31)));
	return (0);
}

int	ft_putarg_in(char *line, void **texture, int *type)
{
	int		i;
	char	*file;

	i = 0;
	file = NULL;
	if (!strncmp(line, "/", 1) || !strncmp(line, "./", 2))
	{
		*type = 1;
		while (line[i] && line[i] != ' ')
			i++;
		file = (char *)malloc((sizeof(char) * i) + 1);
		if (!file)
			exit(1 + (0 * ft_error(INIT_ALLOC)
					* ft_free_base(ft_get_struct(0))));
		file[i] = 0;
		while (--i >= 0)
			file[i] = line[i];
		if (ft_test_file_if_exist(file) < 0)
			exit(1 + (0 * ft_error(NEX_FILE) * ft_free_base(ft_get_struct(0))));
		*texture = file;
	}
	else if (ft_putarg_rgb(line, texture, type))
		exit(1 + (0 * ft_error(BAD_COLOR) * ft_free_base(ft_get_struct(0))));
	return (0);
}

int	ft_putarg_rgb(char *line, void **texture, int *type)
{
	unsigned char	rgba[4];
	int				i;
	int				nbr;

	i = 0;
	ft_bzero(rgba, 4);
	while (*line) // && i < 4)
	{
		nbr = ft_atoi(line);
		if (nbr < 0 || nbr > 255)
			exit(1 + (0 * ft_error(BAD_COLOR)
					* ft_free_base(ft_get_struct(0))));
		rgba[i] = nbr + 0;
		while (*line && ft_isdigit(*(line++)))
			;
		while (*line && !ft_isdigit(*(line)))
			line++;
		if (*line)
			i++;
	}
	if (i < 2 || i > 3)
		exit(1 + (0 * ft_error(BAD_COLOR) * ft_free_base(ft_get_struct(0))));
	*type = 0;
	ft_add_color_texture(rgba, texture);
	return (0);
}

void	ft_add_color_texture(unsigned char *rgba, void **texture)
{
	int	*color;

	color = (int *)malloc(sizeof(int));
	if (!color)
		exit(1 + (0 * ft_error(BAD_COLOR) * ft_free_base(ft_get_struct(0))));
	*color = *color << 8 | rgba[0];
	*color = *color << 8 | rgba[1];
	*color = *color << 8 | rgba[2];
	if (rgba[3])
		*color = *color << 8 | rgba[3];
	else
		*color = *color << 8;
	*texture = color;
	return ;
}

int	ft_test_file_if_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd)
		return (close(fd));
	return (-1);
}
