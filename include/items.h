/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:54:58 by stissera          #+#    #+#             */
/*   Updated: 2022/10/31 14:49:25 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMS_H
#define ITEMS_H

typedef struct s_items
{
	int		id;
	char	*name;
	int		anni; // number img annimation
	void	**sprite;
	int		*decal_x;
	int		*decal_y;
	int		speed; // fps of annim;
	int		type;
	int		add;
}	t_items;

#endif
