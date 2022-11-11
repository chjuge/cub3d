/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fields_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:12:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 17:42:07 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	f_convert(char ch)
{
	if (ch == '1' || ch == ' ')
		return (1);
	else
		return (0);
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
			arr[i][j] = f_convert(tmp->val);
			j++;
			tmp = tmp->next;
		}
		lst = lst->next;
		i++;
	}
	return (arr);
}

int	check_for_dir(char ch, t_map *map, int y, int x)
{
	if (ch == '0' || ch == '1')
		return (0);
	map->start_x = x;
	map->start_y = y;
	if (ch == 'N')
		map->start_dir = NO;
	else if (ch == 'S')
		map->start_dir = SO;
	else if (ch == 'E')
		map->start_dir = EA;
	else
		map->start_dir = WE;
	return (1);
}

int	fill_direct_and_start(t_map *map)
{
	int		i;
	int		j;
	t_list	*lst;
	t_field	*field;

	i = 0;
	lst = map->lst;
	while (i < map->max_y)
	{
		j = 0;
		field = lst->val;
		while (j < map->max_x)
		{
			if (check_for_dir(field->val, map, i, j))
				return (OK);
			j++;
			field = field->next;
		}
		i++;
		lst = lst->next;
	}
	return (ERR);
}

int	fields_to_array(t_map *map)
{
	adjust_length(map, &(map->max_x), &(map->max_y));
	if (fill_direct_and_start(map))
		return (ERR);
	map->map = convert_lst_to_array(map->lst, map->max_x, map->max_y);
	return (OK);
}
