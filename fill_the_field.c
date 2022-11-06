/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:05:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 11:30:27 by mproveme         ###   ########.fr       */
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
		str = get_next_line(fd);
	}
	if (str)
	{
		printf("find bad line!!!\n");
		free(str);
		// str = NULL;
		return (ERR);
	}
	return (OK);
}
