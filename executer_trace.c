/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:11:06 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 17:11:47 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	trace(int x, t_fin_map *map, t_texture **texture, double *place)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	del_dist_x;
	double	del_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit; //was there a wall hit?
	int		side;//was a NS or a EW wall hit?
	int		line_height;
	double	wall_x;
	int		tex_x;

	camera_x = 2 * x / (double)WIN_X - 1;
	ray_dir_x = map->dirX + map->planeX * 0;
	ray_dir_y = map->dirY + map->planeY * camera_x;
	map_x = (int)map->posX;
	map_y = (int)map->posY;
	del_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
	del_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
	hit = 0;
	//calculate step and initial sideDist
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (map->posX - map_x) * del_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - map->posX) * del_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (map->posY - map_y) * del_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - map->posY) * del_dist_y;
	}
	//perform DDA
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += del_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += del_dist_y;
			map_y += step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if (map->map[map_x][map_y] > 0)
			hit = 1;
	}
	if (side == 0)
		perp_wall_dist = (side_dist_x - del_dist_x);
	else
		perp_wall_dist = (side_dist_y - del_dist_y);
	line_height = (int)(WIN_Y / perp_wall_dist);
	if (side == 1)
	{
		if (ray_dir_y > 0.0)
			*texture = map->texture_so;
		else
			*texture = map->texture_no;
	}
	else
	{
		if (ray_dir_x > 0.0)
			*texture = map->texture_we;
		else
			*texture = map->texture_ea;
	}
	if (side == 0)
		wall_x = map->posY + perp_wall_dist * ray_dir_y;
	else
		wall_x = map->posX + perp_wall_dist * ray_dir_x;
	wall_x -= floor((wall_x));
	//x coordinate on the texture
	tex_x = (int)(wall_x * (double)((*texture)->t_w));
	if (side == 0 && ray_dir_x > 0)
		tex_x = (*texture)->t_w - tex_x - 1;
	if (side == 1 && ray_dir_y < 0)
		tex_x = (*texture)->t_w - tex_x - 1;
	*place = tex_x;
	return (line_height / 2);
}
