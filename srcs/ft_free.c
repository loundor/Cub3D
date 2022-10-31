/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:44:22 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 17:26:26 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_free_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (0);
}

int ft_free_tab(char **tab)
{
	size_t	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
	return (0);
}

int	ft_free_base(t_base *base)
{
	ft_putstr_fd("Nettoyage...", 1);
	free(base);
	base = NULL;
	return (0);
}
