/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:58:09 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 18:01:28 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		if ((*texture && !ft_free_str(*texture)) || !*texture)
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
	while (*line && i <= 3)
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
	if (rgba[3])
		*color = *color << 8 | rgba[3];
	else
		*color = *color << 8;
	*color = *color << 8 | rgba[0];
	*color = *color << 8 | rgba[1];
	*color = *color << 8 | rgba[2];
	*texture = color;
	return ;
}

int	ft_map_insert_param(char *line, t_base *base)
{
	if (!ft_strncmp(line, "NO ", 3)) // A voir dans le sujet si N, S, W, E seul passe....
		ft_map_param_no(line, base);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_map_param_so(line, base);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_map_param_we(line, base);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_map_param_ea(line, base);
	else if (!ft_strncmp(line, "F ", 2))
		ft_map_param_f(line, base);
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
