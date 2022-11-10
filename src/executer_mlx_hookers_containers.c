/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_mlx_hookers_containers.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:11:34 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 19:21:59 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	container_keys_left_right(int keycode, double *angle)
{
	if (keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == LEFT)
			*angle = -0.1;
		else
			*angle = 0.1;
		return (1);
	}
	return (0);
}

int	container_keys_w(int keycode, t_fin_map *map,
		double *new_pos_x, double *new_pos_y)
{
	if (keycode == W)
	{
		*new_pos_x = map->pos_x + map->dir_x * 0.1;
		*new_pos_y = map->pos_y + map->dir_y * 0.1;
		return (1);
	}
	return (0);
}

int	container_keys_a(int keycode, t_fin_map *map,
		double *new_pos_x, double *new_pos_y)
{
	if (keycode == A)
	{
		*new_pos_x = map->pos_x + map->dir_y * 0.1;
		*new_pos_y = map->pos_y - map->dir_x * 0.1;
		return (1);
	}
	return (0);
}

int	container_keys_s(int keycode, t_fin_map *map,
		double *new_pos_x, double *new_pos_y)
{
	if (keycode == S)
	{
		*new_pos_x = map->pos_x - map->dir_x * 0.1;
		*new_pos_y = map->pos_y - map->dir_y * 0.1;
		return (1);
	}
	return (0);
}

int	container_keys_d(int keycode, t_fin_map *map,
		double *new_pos_x, double *new_pos_y)
{
	if (keycode == D)
	{
		*new_pos_x = map->pos_x - map->dir_y * 0.1;
		*new_pos_y = map->pos_y + map->dir_x * 0.1;
		return (1);
	}
	return (0);
}
