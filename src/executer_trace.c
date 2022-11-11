/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:11:06 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 15:23:47 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	trace_step1(t_trace *t, int x, t_fin_map *map)
{
	t->camera_x = 2 * x / (double)WIN_X - 1;
	t->ray_dir_x = map->dir_x + map->plane_x * t->camera_x;
	t->ray_dir_y = map->dir_y + map->plane_y * t->camera_x;
	t->map_x = (int)map->pos_x;
	t->map_y = (int)map->pos_y;
	t->del_dist_x = sqrt(1 + (t->ray_dir_y * t->ray_dir_y)
			/ (t->ray_dir_x * t->ray_dir_x));
	t->del_dist_y = sqrt(1 + (t->ray_dir_x * t->ray_dir_x)
			/ (t->ray_dir_y * t->ray_dir_y));
	t->hit = 0;
}

void	trace_step2(t_trace *t, t_fin_map *map)
{
	if (t->ray_dir_x < 0)
	{
		t->step_x = -1;
		t->side_dist_x = (map->pos_x - t->map_x) * t->del_dist_x;
	}
	else
	{
		t->step_x = 1;
		t->side_dist_x = (t->map_x + 1.0 - map->pos_x) * t->del_dist_x;
	}
	if (t->ray_dir_y < 0)
	{
		t->step_y = -1;
		t->side_dist_y = (map->pos_y - t->map_y) * t->del_dist_y;
	}
	else
	{
		t->step_y = 1;
		t->side_dist_y = (t->map_y + 1.0 - map->pos_y) * t->del_dist_y;
	}	
}

void	trace_step3(t_trace *t, t_fin_map *map)
{
	while (t->hit == 0)
	{
		if (t->side_dist_x < t->side_dist_y)
		{
			t->side_dist_x += t->del_dist_x;
			t->map_x += t->step_x;
			t->side = 0;
		}
		else
		{
			t->side_dist_y += t->del_dist_y;
			t->map_y += t->step_y;
			t->side = 1;
		}
		if (map->map[t->map_x][t->map_y] > 0)
			t->hit = 1;
	}
}

void	trace_step4(t_trace *t, t_fin_map *map, t_texture **texture)
{
	if (t->side == 0)
		t->perp_wall_dist = (t->side_dist_x - t->del_dist_x);
	else
		t->perp_wall_dist = (t->side_dist_y - t->del_dist_y);
	t->line_height = (int)(WIN_Y / t->perp_wall_dist);
	if (t->side == 1)
	{
		if (t->ray_dir_y > 0.0)
			*texture = map->texture_so;
		else
			*texture = map->texture_no;
	}
	else
	{
		if (t->ray_dir_x > 0.0)
			*texture = map->texture_we;
		else
			*texture = map->texture_ea;
	}
}

int	trace(int x, t_fin_map *map, t_texture **texture, double *place)
{
	t_trace	t;

	trace_step1(&t, x, map);
	trace_step2(&t, map);
	trace_step3(&t, map);
	trace_step4(&t, map, texture);
	if (t.side == 0)
		t.wall_x = map->pos_y + t.perp_wall_dist * t.ray_dir_y;
	else
		t.wall_x = map->pos_x + t.perp_wall_dist * t.ray_dir_x;
	t.wall_x -= floor((t.wall_x));
	t.tex_x = (int)(t.wall_x * (double)((*texture)->t_w));
	if (t.side == 0 && t.ray_dir_x > 0)
		t.tex_x = (*texture)->t_w - t.tex_x - 1;
	if (t.side == 1 && t.ray_dir_y < 0)
		t.tex_x = (*texture)->t_w - t.tex_x - 1;
	*place = t.tex_x;
	return (t.line_height / 2);
}
