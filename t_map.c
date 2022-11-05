/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:50:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 20:00:44 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->texture_ea = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_no = NULL;
	map->map = NULL;
	map->color_c = -1;
	map->color_f = -1;
	map->start_x = -1;
	map->start_y = -1;
	map->start_dir = -1;
	map->lst = NULL;

	return (map);
}

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

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->texture_no)
		free(map->texture_no);
	if (map->texture_so)
		free(map->texture_so);
	if (map->texture_we)
		free(map->texture_we);
	if (map->texture_ea)
		free(map->texture_ea);
	if (map->map)
		free_int_arr(map->map);
	if (map->lst)
	{
		// printf("map	%p\n", map);
		// printf("lst	%p\n", map->lst);
		// printf("val	%p\n\n\n", map->lst->val);
		// read_lines(map->lst);
		free_lists_all(map->lst); //1
	}
	free(map);
}
