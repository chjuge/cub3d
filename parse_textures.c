/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 19:11:49 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_textures(t_fin_map *fin, t_map *map)
{
	fin->mlx = mlx_init();
	fin->texture_no->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_no, &(fin->texture_no->t_w), &(fin->texture_no->t_h));
	if (fin->texture_no->txtr == NULL)
		return (ERR);
	printf("1 successfull\n");
	fin->texture_so->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_so, &(fin->texture_so->t_w), &(fin->texture_so->t_h));
	if (fin->texture_so->txtr == NULL)
		return (ERR);
	printf("2 successfull\n");
	fin->texture_we->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_we, &(fin->texture_we->t_w), &(fin->texture_we->t_h));
	if (fin->texture_we->txtr == NULL)
		return (ERR);
	printf("3 successfull\n");
	fin->texture_ea->txtr = mlx_xpm_file_to_image(fin->mlx, 
		map->path_to_txt_ea, &(fin->texture_ea->t_w), &(fin->texture_ea->t_h));
	if (fin->texture_ea->txtr == NULL)
		return (ERR);

	return (OK);	
}

