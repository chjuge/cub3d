/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:32:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list	*init_list(void)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->next = NULL;
	res->val = NULL;
	return (res);
}

t_list	*list_last(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_list(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = list_last(tmp);
	tmp->next = new;
}

void	free_lists_all(t_list *t)
{
	t_list	*tmp;

	if (t == NULL)
		return ;
	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_fields_all(tmp->val);
		free(tmp);
	}
}
