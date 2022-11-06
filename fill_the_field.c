/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:05:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:49 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_field	*fill_list(char *str, t_map *map)
{
	int	len;
	int	i;
	t_field	*tmp;
	t_field	*field;

	len = ft_strlen_n(str);
	i = 0;
	field = NULL;
	while (i < len)
	{
		tmp = init_field(str[i], map);
		add_back_field(&field, tmp);
		i++;
	}
	return (field);
}

void	fill_start_xy(t_map *map)
{
	int 	i;
	int		j;
	t_list	*tmpl;
	t_field	*tmpf;

	i = 1;
	j = 1;
	tmpl = map->lst;
	while (tmpl->next)
	{
		i++;
		tmpl = tmpl->next;
	}
	tmpf = tmpl->val;
	while (tmpf->next)
	{
		j++;
		tmpf = tmpf->next;
	}
	map->start_x = j;
	map->start_y = i;
}

int	check_first_last_walls(t_field *lst)
{
	t_field	*last;

	if (lst->val == 0)
		return (ERR);
	last = field_last(lst);
	if (last->val == 0)
		return (ERR);
	return (OK);
}

int	check_line_for_zeros(t_field *lst)
{
	while (lst)
	{
		if (lst->val == 0)
			return (ERR);
		lst = lst->next;
	}
	return (OK);
}

int	check_first_last_lines(t_list *lst)
{
	if (check_line_for_zeros(lst->val))
		return (ERR);
	lst = list_last(lst);
	if (check_line_for_zeros(lst->val))
		return (ERR);
	return (OK);
}


int	fill_the_field(t_map *map, char *str, int fd)
{
	t_list	*tmp;

	while (check_for_field(str) == OK)
	{
		printf("str:	'%s'", str);
		tmp = init_list();
		tmp->val = fill_list(str, map);
		add_back_list(&(map->lst), tmp);
		if (map->start_x != -1 || map->start_dir != -1)
			fill_start_xy(map);
		free(str);
		if (check_first_last_walls(tmp->val))
			return (ERR);
		str = get_next_line(fd);
	}
	if (str)
	{
		printf("find bad line!!!\n");
		free(str);
		return (ERR);
	}
	if (check_first_last_lines(map->lst))
		return (ERR);
	return (OK);
}
