/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:50:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 19:51:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->path_to_txt_ea = NULL;
	map->path_to_txt_so = NULL;
	map->path_to_txt_we = NULL;
	map->path_to_txt_no = NULL;
	map->map = NULL;
	map->color_c = -1;
	map->color_f = -1;
	map->start_x = -1;
	map->start_y = -1;
	map->start_dir = -1;
	map->lst = NULL;
	map->max_x = 0;
	map->max_y = 0;
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
	if (map->path_to_txt_no)
		free(map->path_to_txt_no);// удалять
	if (map->path_to_txt_so)
		free(map->path_to_txt_so);// удалять
	if (map->path_to_txt_we)
		free(map->path_to_txt_we);// удалять
	if (map->path_to_txt_ea)
		free(map->path_to_txt_ea); // удалять
	if (map->lst)
		free_lists_all(map->lst); // удалять
	free(map);
}


void	free_img(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

void	free_text_imgs(t_fin_map *map)
{
	if (map->texture_ea)
	{
		if ((map->texture_ea)->txtr)
			mlx_destroy_image(map->mlx, (map->texture_ea)->txtr);
		free(map->texture_ea);
	}
	if (map->texture_no)
	{
		if ((map->texture_no)->txtr)
			mlx_destroy_image(map->mlx, (map->texture_no)->txtr);
		free(map->texture_no);
	}
	if (map->texture_so)
	{
		if ((map->texture_so)->txtr)
			mlx_destroy_image(map->mlx, (map->texture_so)->txtr);
		free(map->texture_so);
	}
	if (map->texture_we)
	{
		if ((map->texture_we)->txtr)
			mlx_destroy_image(map->mlx, (map->texture_we)->txtr);
		free(map->texture_we);
	}
}

void	free_final_map(t_fin_map *map)
{
	free_text_imgs(map);
	if (map->map)
		free_int_arr(map->map);
	// if (map->mlx)
		// free(map->mlx);
	free(map);
}
