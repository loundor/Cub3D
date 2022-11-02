/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_file_if_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:11:40 by stissera          #+#    #+#             */
/*   Updated: 2022/11/02 17:07:44 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_test_file_if_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd)
		return (close(fd));
	return (-1);
}
