/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_readers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:30:01 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:21:55 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	read_t_map(t_map *map)
{
	read_int_map(map->map, map->max_x, map->max_y);
	printf("\ncolor	floor	%d\n", map->color_f);
	printf("color	ceil	%d\n", map->color_c);
	printf("\ntexture no	%s\n", map->path_to_txt_no);
	printf("texture so	%s\n", map->path_to_txt_so);
	printf("texture ea	%s\n", map->path_to_txt_ea);
	printf("texture we	%s\n", map->path_to_txt_we);
	printf("max_x	%d\n", map->max_x);
	printf("max_y	%d\n", map->max_y);
}

void	read_int_map(int	**map, int max_x, int max_y)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}	
}

void	read_lines(t_list	*lst)
{
	t_field	*tmp;

	while (lst)
	{
		tmp = lst->val;
		while (tmp)
		{
			printf("%d,", tmp->val);
			tmp = tmp->next;
		}
		lst = lst->next;
		printf("\n");
	}
	printf("\n");
}
