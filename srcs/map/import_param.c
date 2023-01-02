/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:58:09 by stissera          #+#    #+#             */
/*   Updated: 2023/01/02 14:36:33 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_putarg_in(char *line, t_img *texture, t_game *g)
{
	int		i;
	char	*file;

	i = 0;
	file = NULL;
	if (!strncmp(line, "./", 2) || !strncmp(line, "../", 3))
	{
		while (line[i] && line[i] != ' ')
			i++;
		file = (char *)malloc((sizeof(char) * i) + 1);
		if (!file)
			exit(1 + (0 * ft_error(INIT_ALLOC)));
		file[i] = 0;
		while (--i >= 0)
			file[i] = line[i];
		texture->img = mlx_xpm_file_to_image(g->mlx, file, &texture->width,
				&texture->heihgt);
		ft_free_str(file);
		if (!texture->img)
			exit(1 + (0 * ft_error(NEX_FILE)));
	}
	else if (ft_putarg_rgb(line, texture))
		exit(1 + (0 * ft_error(BAD_COLOR)));
	return (0);
}

int	ft_putarg_rgb(char *line, t_img *texture)
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
			exit(1 + (0 * ft_error(BAD_COLOR)));
		rgba[i] = nbr + 0;
		while (*line && ft_isdigit(*(line++)))
			;
		while (*line && !ft_isdigit(*(line)))
			line++;
		if (*line)
			i++;
	}
	if (i < 2 || i > 3)
		exit(1 + (0 * ft_error(BAD_COLOR)));
	if (!rgba[4])
		rgba[4] = 0;
	ft_add_color_texture(rgba, texture);
	return (0);
}

void	ft_add_color_texture(char *rgba, t_img *texture)
{
	unsigned int	color;
	t_game			*g;

	color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | rgba[4];
	g = ft_get_struct(NULL);
	texture->img = mlx_new_image(g->mlx, 1, 1);
	texture->addr = mlx_get_data_addr(texture->img, texture->bits_per_pixel,
			texture->line_length, texture->endian);
	texture->addr = color;
	return ;
}

int	ft_map_insert_param(char *line, t_game *base)
{
	if (!ft_strncmp(line, "NO ", 3))
		ft_map_param_wf(line, base, 0);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_map_param_wf(line, base, 1);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_map_param_wf(line, base, 2);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_map_param_wf(line, base, 3);
	else if (!ft_strncmp(line, "F ", 2))
		ft_map_param_wf(line, base, 4);
	else if (!ft_strncmp(line, "C ", 2))
		ft_map_param_wf(line, base, 5);
	else
		return (-1 + (0 * write(1, "Invalid argurment in map file!\n", 31)));
	return (0);
}

int	ft_map_param_wf(char *line, t_game *g, int i)
{
	if (i == 4 || i == 5)
		line += 2;
	else
		line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &g->map->texture[i], g);
	return (0);
}
