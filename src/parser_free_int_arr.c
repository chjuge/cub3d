/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_int_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:18:41 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:30 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_int_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
