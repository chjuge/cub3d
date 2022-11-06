/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 13:01:00 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_textures(t_map *map)
{
	int		img_w;
	int		img_h;
	
	map->mlx = mlx_init();
	map->texture_ea = mlx_xpm_file_to_image(map->mlx, map->path_to_txt_ea, &img_w, &img_h);
	if (map->texture_ea == NULL)
		return (ERR);
	printf("1 successfull\n");
	map->texture_no = mlx_xpm_file_to_image(map->mlx, map->path_to_txt_no, &img_w, &img_h);
	if (map->texture_ea == NULL)
		return (ERR);
	printf("2 successfull\n");
	map->texture_so = mlx_xpm_file_to_image(map->mlx, map->path_to_txt_so, &img_w, &img_h);
	if (map->texture_ea == NULL)
		return (ERR);
	printf("3 successfull\n");
	map->texture_we = mlx_xpm_file_to_image(map->mlx, map->path_to_txt_we, &img_w, &img_h);
	if (map->texture_ea == NULL)
		return (ERR);
	return (OK);	
}

