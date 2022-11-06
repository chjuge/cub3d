/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:30:01 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 11:36:01 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	read_t_map(t_map *map)
{
	read_int_map(map->map);
	printf("\ncolor	floor	%d\n", map->color_f);
	printf("color	ceil	%d\n", map->color_c);
	printf("\ntexture no	%s\n", map->path_to_txt_no);
	printf("texture so	%s\n", map->path_to_txt_so);
	printf("texture ea	%s\n", map->path_to_txt_ea);
	printf("texture we	%s\n", map->path_to_txt_we);
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
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}	
}

void	read_lines(t_list	*lst)
{
	printf("read_lines\n");
	t_field	*tmp;

	while (lst)
	{
		// printf("QWQWQW\n");
		tmp = lst->val;
		// printf("%d\n",tmp->val);
		while (tmp)
		{
			printf("%d,",tmp->val);
			tmp = tmp->next;
		}
		lst = lst->next;
		printf("\n");
	}
	printf("\n");
}