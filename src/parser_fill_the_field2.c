/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_the_field2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:05:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 13:44:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_first_last_walls(t_field *lst)
{
	if (lst->val == '0' || lst->val == 'N' || lst->val == 'S'
		|| lst->val == 'W' || lst->val == 'E')
		return (ERR);
	lst = field_last(lst);
	if (lst->val == '0' || lst->val == 'N' || lst->val == 'S'
		|| lst->val == 'W' || lst->val == 'E')
		return (ERR);
	return (OK);
}

int	check_line_for_zeros(t_field *lst)
{
	while (lst)
	{
		if (lst->val == '0' || lst->val == 'N' || lst->val == 'S'
			|| lst->val == 'W' || lst->val == 'E')
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
