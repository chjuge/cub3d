/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parser3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 14:26:36 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_for_field(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\n')
		return (ERR);
	while (str[i] && str[i] != '\n')
	{
		if (cmp_with_admissible(str[i]) == ERR)
		{
			return (ERR);
		}
		i++;
	}
	return (OK);
}
