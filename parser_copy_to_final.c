/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_copy_to_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:42:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 15:42:45 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_fin_map	*copy_to_final(t_map *map)
{
	t_fin_map	*res;

	res = malloc(sizeof(t_fin_map));
	res->texture_ea = malloc(sizeof(t_texture));
	res->texture_no = malloc(sizeof(t_texture));
	res->texture_so = malloc(sizeof(t_texture));
	res->texture_we = malloc(sizeof(t_texture));
	res->color_c = map->color_c;
	res->color_f = map->color_f;
	res->map = map->map;
	res->start_x = map->start_x;
	res->start_y = map->start_y;
	res->start_dir = map->start_dir;
	res->max_x = map->max_x;
	res->max_y = map->max_y;
	return (res);
}
