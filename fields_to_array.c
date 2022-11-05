/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 17:38:24 by mproveme         ###   ########.fr       */
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
	add_back_field(&(lst->val), init_field_2(val2));
}

void	add_wall_back(t_list *lst)
{
	add_back_field(&(lst->val), init_field_2(1));
}

void	adjust_front_back(t_map *map)
{
	t_list *tmp;

	tmp = map->lst;
	while (tmp)
	{
		if (tmp->val->val == 0)
			add_wall_front(tmp);
		if (field_last(tmp->val)->val == 0)
			add_wall_back(tmp);
		tmp = tmp->next;
	}
}

int	find_max_len_line(t_list *lst)
{
	int		i;
	int		j;
	t_field	*tmp;

	i = 0;
	while (lst)
	{
		j = 0;
		tmp = lst->val;
		while (tmp)
		{
			j++;
			tmp = tmp->next;
		}
		if (j > i)
			i = j;
		lst = lst->next;
	}
	return (i);
}

void	line_to_length(t_list *lst, int i)
{
	t_field	*tmp;
	int		j;

	j = 0;
	tmp = lst->val;
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	while (j < i)
	{
		j++;
		add_back_field(&(lst->val), init_field_2(1));
	}
}

void	adjust_length(t_map *map)
{
	int		i;
	t_list	*tmp;

	i = find_max_len_line(map->lst);
	tmp = map->lst;
	while (tmp)
	{
		line_to_length(tmp, i);
		tmp = tmp->next;
	}
}

int	fields_to_array(t_map *map)
{
	// int	max_x;
	// int	max_y;

	adjust_front_back(map);
	adjust_length(map);
	return (OK);
}
