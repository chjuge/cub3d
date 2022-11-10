/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 17:21:59 by mproveme         ###   ########.fr       */
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

void	adjust_length(t_map *map, int *x, int *y)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = find_max_len_line(map->lst);
	j = 0;
	tmp = map->lst;
	while (tmp)
	{
		line_to_length(tmp, i);
		tmp = tmp->next;
		j++;
	}
	*x = i;
	*y = j;
}

int	**convert_lst_to_array(t_list *lst, int x, int y) ///!!!!!!!
{
	int	**arr;
	int	i;
	int	j;
	t_field	*tmp;

	arr = malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		arr[i] = malloc(sizeof(int) * x);
		j = 0;
		tmp = lst->val;
		while (j < x)
		{
			arr[i][j] = tmp->val;
			j++;
			tmp = tmp->next; 
		}
		lst = lst->next;
		i++;
	}
	return (arr);
}

void fields_to_array(t_map *map)
{

	// read_lines(map->lst);
	// adjust_front_back(map);
	adjust_length(map, &(map->max_x), &(map->max_y));
	// read_lines(map->lst);

	// printf("map	%p\nmap.lst	%p\nmap.map	%p\n", map, map->lst, map->map);
	map->map = convert_lst_to_array(map->lst, map->max_x, map->max_y);
	// read_int_map(map->map);
}
