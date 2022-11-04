/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/04 20:25:00 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_wall_front(t_list *lst)
{
	t_field	*tmp;
	int		val1;
	int		val2;

	tmp = lst->val;
	val2 = 1;
	while (tmp)
	{
		val1 = tmp->val;
		tmp->val = val2;
		val2 = val1;
		tmp = tmp->next;
	}
}

void	adjust_walls(t_map *map)
{
	t_list *tmp;

	tmp = map->lst;
	while (tmp)
	{
		if (tmp->val->val == 0)
			add_wall_front(tmp);
	}
}

int	fields_to_array(t_map *map)
{
	int	max_x;
	int	max_y;

	adjust_walls(map);
	return (OK);
}
