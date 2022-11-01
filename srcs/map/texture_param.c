/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:59:47 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:00:29 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_map_param_no(char *line, t_base *base)
{
	line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &base->map->texture_n, &base->map->wall_n);
	return (0);
}

int	ft_map_param_so(char *line, t_base *base)
{
	line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &base->map->texture_s, &base->map->wall_s);
	return (0);
}

int	ft_map_param_we(char *line, t_base *base)
{
	line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &base->map->texture_w, &base->map->wall_w);
	return (0);
}

int	ft_map_param_ea(char *line, t_base *base)
{
	line += 3;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &base->map->texture_e, &base->map->wall_e);
	return (0);
}

int	ft_map_param_f(char *line, t_base *base)
{
	line += 2;
	while (line && *line == ' ')
		line++;
	if (*line)
		ft_putarg_in(line, &base->map->texture_f, &base->map->floor);
	return (0);
}
