/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_full_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:26:12 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/04 16:32:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_for_full_map(t_map *map)
{
	if (!map->map || !map->texture_ea || !map->texture_no
		|| !map->texture_so || !map->texture_we)
		return (ERR);
	if (map->color_c == -1 || map->color_f == -1)
		return (ERR);
	if (map->start_x == -1 || map->start_y == -1 || map->start_dir == -1)
		return (ERR);
	return (OK);
}
