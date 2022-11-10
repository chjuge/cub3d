/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hookers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:11:34 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 02:05:44 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		red_button(void *param)
{
	t_fin_map *map;

	map = (t_fin_map *)param;
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_image(map->mlx, map->image.image);
	exit(0);
}

int		manage_mouse(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

void	validate(t_fin_map *map, double new_pos_x, double new_pos_y)
{
	if (new_pos_x < 0.0 || new_pos_y < 0.0 || new_pos_x >= (double)map->max_y
		|| new_pos_y >= (double)map->max_x
		|| map->map[(int)new_pos_x][(int)new_pos_y])
		return ;
	map->posX = new_pos_x;
	map->posY = new_pos_y;
}

int		manage_key(int keycode, void *param)
{
	t_fin_map	*map;
	double		angle;
	double		new_pos_x;
	double		new_pos_y;

	map = (t_fin_map *)param;
	if (keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == LEFT)
			angle = -0.1;
		else
			angle = 0.1;
		rotate_vec(&map->dirX, &map->dirY, angle);
		rotate_vec(&map->planeX, &map->planeY, angle);
	}
	if (keycode == W)
	{

		new_pos_x = map->posX + map->dirX * 0.1;
		new_pos_y = map->posY + map->dirY * 0.1;
		validate(map, new_pos_x, new_pos_y);
	}
	if (keycode == S)
	{
		new_pos_x = map->posX - map->dirX * 0.1;
		new_pos_y = map->posY - map->dirY * 0.1;
		validate(map, new_pos_x, new_pos_y);
	}
	if (keycode == A)
	{
		new_pos_x = map->posX + map->dirY * 0.1;
		new_pos_y = map->posY - map->dirX * 0.1;
		validate(map, new_pos_x, new_pos_y);
	}
	if (keycode == D)
	{
		new_pos_x = map->posX - map->dirY * 0.1;
		new_pos_y = map->posY + map->dirX * 0.1;
		validate(map, new_pos_x, new_pos_y);
	}
	if (keycode == ESC)
	{
		mlx_destroy_image(map->mlx, map->image.image);
		mlx_destroy_window(map->mlx, map->window);
		exit (0);
	}
	draw_frame(map);
	return (0);
}

int		manage_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
