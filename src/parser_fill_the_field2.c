/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_the_field2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:05:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:28 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
