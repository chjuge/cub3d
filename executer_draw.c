/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:41:50 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 17:07:39 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_vec(double *x, double *y, double angle)
{
	double	new_x;
	double	new_y;

	new_x = (*x) * cos(angle) - (*y) * sin(angle);
	new_y = (*x) * sin(angle) + (*y) * cos(angle);
	*x = new_x;
	*y = new_y;
}

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

int	get_image_pixel(t_image *image, int x, int y)
{
	char			*dst;
	unsigned int	dbl;

	dst = image->addr + (y * image->line_length + x *
			(image->bits_per_pixel / 8));
	if (image->endian == 0)
	{
		dbl = *(unsigned int *)dst;
		// dbl >>= 8;
		dbl = (dbl & 0x00FFFFFF);// >> 24) + ((dbl & 0x00FF0000) >> 8) + ((dbl & 0x0000FF00) << 8);
		return (dbl);
	}
	return (*dst);
}

void	image_pixel(t_image *image,int color, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	real_draw(t_fin_map *map, double intersec, int column,
		t_texture *texture, double place)
{
	int	upper_fr;
	int	lower_fr;
	int	count;
	int	tex_color;

	count = 0;
	upper_fr = WIN_Y / 2 - (int)intersec;
	lower_fr = WIN_Y / 2 + (int)intersec;
	while (count < WIN_Y)
	{
		if (count < upper_fr)
			image_pixel(&map->image, map->color_c, column, count);
		else if (count > lower_fr)
			image_pixel(&map->image, map->color_f, column, count);
		else
		{
			tex_color = get_image_pixel(&texture->image, (int)place,
				((count - upper_fr) * texture->t_h) / (2 * (int)intersec));
			image_pixel(&map->image, tex_color, column, count);
		}
		count++;
	}
}

void	draw_column(t_fin_map *map, int column)
{
	int			intersec;
	t_texture	*texture;
	double		place;

	intersec = trace(column, map, &texture, &place);
	real_draw(map, intersec, column, texture, place);
}

void	draw_frame(t_fin_map *map)
{
	int	count;
	void	*old_image;

	old_image = map->image.image;
	map->image.image = mlx_new_image(map->mlx, WIN_X, WIN_Y);
	map->image.addr = mlx_get_data_addr(map->image.image,
		&map->image.bits_per_pixel, &map->image.line_length,
		&map->image.endian);
	count = 0;
	while (count < WIN_X)
	{
		draw_column(map, count);
		count++;
	}
	mlx_put_image_to_window(map->mlx, map->window, map->image.image, 0, 0);
	if (old_image)
		mlx_destroy_image(map->mlx, old_image);
}
