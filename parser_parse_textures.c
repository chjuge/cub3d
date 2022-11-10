/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 13:44:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_texture1(t_fin_map *fin, t_map *map)
{
	fin->texture_no->txtr = mlx_xpm_file_to_image(
			fin->mlx,
			map->path_to_txt_no,
			&(fin->texture_no->t_w),
			&(fin->texture_no->t_h));
}

void	parse_texture2(t_fin_map *fin, t_map *map)
{
	fin->texture_so->txtr = mlx_xpm_file_to_image(
			fin->mlx,
			map->path_to_txt_so,
			&(fin->texture_so->t_w),
			&(fin->texture_so->t_h));
}

void	parse_texture3(t_fin_map *fin, t_map *map)
{
	fin->texture_we->txtr = mlx_xpm_file_to_image(
			fin->mlx,
			map->path_to_txt_we,
			&(fin->texture_we->t_w),
			&(fin->texture_we->t_h));
}

void	parse_texture4(t_fin_map *fin, t_map *map)
{
	fin->texture_ea->txtr = mlx_xpm_file_to_image(
			fin->mlx,
			map->path_to_txt_ea,
			&(fin->texture_ea->t_w),
			&(fin->texture_ea->t_h));
}

int	parse_textures(t_fin_map *fin, t_map *map)
{
	fin->mlx = mlx_init();
	parse_texture1(fin, map);
	if (fin->texture_no->txtr == NULL)
		return (ERR);
	fill_addr1(fin);
	parse_texture2(fin, map);
	if (fin->texture_so->txtr == NULL)
		return (ERR);
	fill_addr2(fin);
	parse_texture3(fin, map);
	if (fin->texture_we->txtr == NULL)
		return (ERR);
	fill_addr3(fin);
	parse_texture4(fin, map);
	if (fin->texture_ea->txtr == NULL)
		return (ERR);
	fill_addr4(fin);
	return (OK);
}
