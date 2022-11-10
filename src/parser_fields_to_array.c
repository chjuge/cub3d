/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fields_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:24 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

int	**convert_lst_to_array(t_list *lst, int x, int y)
{
	int		**arr;
	int		i;
	int		j;
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

void	fields_to_array(t_map *map)
{
	adjust_length(map, &(map->max_x), &(map->max_y));
	map->map = convert_lst_to_array(map->lst, map->max_x, map->max_y);
}
