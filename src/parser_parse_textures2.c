/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_textures2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:35 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	fill_addr1(t_fin_map *fin)
{
	fin->texture_no->image.image = fin->texture_no->txtr;
	fin->texture_no->image.addr = mlx_get_data_addr(
			fin->texture_no->image.image,
			&fin->texture_no->image.bits_per_pixel,
			&fin->texture_no->image.line_length,
			&fin->texture_no->image.endian);
}

void	fill_addr2(t_fin_map *fin)
{
	fin->texture_so->image.image = fin->texture_so->txtr;
	fin->texture_so->image.addr = mlx_get_data_addr(
			fin->texture_so->image.image,
			&fin->texture_so->image.bits_per_pixel,
			&fin->texture_so->image.line_length,
			&fin->texture_so->image.endian);
}

void	fill_addr3(t_fin_map *fin)
{
	fin->texture_we->image.image = fin->texture_we->txtr;
	fin->texture_we->image.addr = mlx_get_data_addr(
			fin->texture_we->image.image,
			&fin->texture_we->image.bits_per_pixel,
			&fin->texture_we->image.line_length,
			&fin->texture_we->image.endian);
}

void	fill_addr4(t_fin_map *fin)
{
	fin->texture_ea->image.image = fin->texture_ea->txtr;
	fin->texture_ea->image.addr = mlx_get_data_addr(
			fin->texture_ea->image.image,
			&fin->texture_ea->image.bits_per_pixel,
			&fin->texture_ea->image.line_length,
			&fin->texture_ea->image.endian);
}
