/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_field.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:32:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 14:14:20 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_field	*init_field(char ch, t_map *map)
{
	t_field	*res;

	res = malloc(sizeof(t_field));
	res->next = NULL;
	if (ch == ' ' || ch == '1')
		res->val = 1;
	else
	{
		res->val = 0;
		if (ch == 'N')
			map->start_dir = NO;
		else if (ch == 'S')
			map->start_dir = SO;
		else if (ch == 'W')
			map->start_dir = WE;
		else
			map->start_dir = EA;
	}
	return (res);
}

t_field	*init_field_2(int n)
{
	t_field	*res;

	res = malloc(sizeof(t_field));
	res->next = NULL;
	res->val = n;
	return (res);
}

t_field	*field_last(t_field *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_field(t_field **lst, t_field *new)
{
	t_field	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = field_last(tmp);
	tmp->next = new;
}

void	free_fields_all(t_field *t)
{
	t_field	*tmp;

	if (t == NULL)
		return ;
	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
}
