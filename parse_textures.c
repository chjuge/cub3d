/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 00:31:24 by ilya             ###   ########.fr       */
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
	fin->texture_no->image.image = fin->texture_no->txtr;
	fin->texture_no->image.addr = mlx_get_data_addr(fin->texture_no->image.image,
		&fin->texture_no->image.bits_per_pixel, &fin->texture_no->image.line_length,
		&fin->texture_no->image.endian);
	printf("1 successfull\n");
	fin->texture_so->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_so, &(fin->texture_so->t_w), &(fin->texture_so->t_h));
	if (fin->texture_so->txtr == NULL)
		return (ERR);
	fin->texture_so->image.image = fin->texture_so->txtr;
	fin->texture_so->image.addr = mlx_get_data_addr(fin->texture_so->image.image,
		&fin->texture_so->image.bits_per_pixel, &fin->texture_so->image.line_length,
		&fin->texture_so->image.endian);
	printf("2 successfull\n");
	fin->texture_we->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_we, &(fin->texture_we->t_w), &(fin->texture_we->t_h));
	if (fin->texture_we->txtr == NULL)
		return (ERR);
	fin->texture_we->image.image = fin->texture_we->txtr;
	fin->texture_we->image.addr = mlx_get_data_addr(fin->texture_we->image.image,
		&fin->texture_we->image.bits_per_pixel, &fin->texture_we->image.line_length,
		&fin->texture_we->image.endian);
	printf("3 successfull\n");
	fin->texture_ea->txtr = mlx_xpm_file_to_image(fin->mlx,
		map->path_to_txt_ea, &(fin->texture_ea->t_w), &(fin->texture_ea->t_h));
	if (fin->texture_ea->txtr == NULL)
		return (ERR);
	fin->texture_ea->image.image = fin->texture_ea->txtr;
	fin->texture_ea->image.addr = mlx_get_data_addr(fin->texture_ea->image.image,
		&fin->texture_ea->image.bits_per_pixel, &fin->texture_ea->image.line_length,
		&fin->texture_ea->image.endian);
	return (OK);
}

