/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:30:01 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 18:35:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	read_t_map(t_map *map)
{
	read_int_map(map->map);
}

void	read_int_map(int	**map)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != -1)
		{
			printf("%d	", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}	
}