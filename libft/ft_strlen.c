/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:49:04 by stissera          #+#    #+#             */
/*   Updated: 2022/09/19 21:15:00 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s || s == NULL || s == 0)
		return (0);
	len = 0;
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}
