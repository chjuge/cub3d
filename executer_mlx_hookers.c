/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_mlx_hookers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:11:34 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 19:01:45 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	red_button(void *param)
{
	t_fin_map	*map;

	map = (t_fin_map *)param;
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_image(map->mlx, map->image.image);
	exit(0);
}

void	validate(t_fin_map *map, double new_pos_x, double new_pos_y)
{
	if (new_pos_x < 0.0 || new_pos_y < 0.0 || new_pos_x >= (double)map->max_y
		|| new_pos_y >= (double)map->max_x
		|| map->map[(int)new_pos_x][(int)new_pos_y])
		return ;
	map->pos_x = new_pos_x;
	map->pos_y = new_pos_y;
}

void	rotate_plus(double angle, t_fin_map *map)
{
	rotate_vec(&map->dir_x, &map->dir_y, angle);
	rotate_vec(&map->planeX, &map->planeY, angle);
}

int	manage_key(int keycode, void *param)
{
	t_fin_map	*map;
	double		angle;
	double		new_pos_x;
	double		new_pos_y;

	map = (t_fin_map *)param;
	if (container_keys_left_right(keycode, &angle))
		rotate_plus(angle, map);
	else if (container_keys_w(keycode, map, &new_pos_x, &new_pos_y))
		validate(map, new_pos_x, new_pos_y);
	else if (container_keys_s(keycode, map, &new_pos_x, &new_pos_y))
		validate(map, new_pos_x, new_pos_y);
	else if (container_keys_a(keycode, map, &new_pos_x, &new_pos_y))
		validate(map, new_pos_x, new_pos_y);
	else if (container_keys_d(keycode, map, &new_pos_x, &new_pos_y))
		validate(map, new_pos_x, new_pos_y);
	else if (keycode == ESC)
	{
		mlx_destroy_image(map->mlx, map->image.image);
		mlx_destroy_window(map->mlx, map->window);
		exit (0);
	}
	draw_frame(map);
	return (0);
}
