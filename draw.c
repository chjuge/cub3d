/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:41:50 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 12:54:39 by sbrella          ###   ########.fr       */
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
	double cameraX = 2*x/(double)WIN_X-1;
	double rayDirX = map->dirX + map->planeX*cameraX;
	double rayDirY = map->dirY + map->planeY*cameraX;

	int mapX = (int)map->posX;
	int mapY = (int)map->posY;

	double sideDistX;
	double sideDistY;

	double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
	double perpWallDist;

	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

	//calculate step and initial sideDist
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (map->posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - map->posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (map->posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - map->posY) * deltaDistY;
	}
	//perform DDA
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		if (map->map[mapX][mapY] > 0)
			hit = 1;
	}
	if(side == 0)
		perpWallDist = (sideDistX - deltaDistX);
	else
		perpWallDist = (sideDistY - deltaDistY);
	int lineHeight = (int)(WIN_Y / perpWallDist);
	if (side == 1)
	{
		if (rayDirY > 0.0)
			*texture = map->texture_so;
		else
			*texture = map->texture_no;
	}
	else
	{
		if (rayDirX > 0.0)
			*texture = map->texture_we;
		else
			*texture = map->texture_ea;
	}
	double wallX;
	if (side == 0)
		wallX = map->posY + perpWallDist * rayDirY;
	else
		wallX = map->posX + perpWallDist * rayDirX;
	wallX -= floor((wallX));

	//x coordinate on the texture
	int texX = (int)(wallX * (double)((*texture)->t_w));
	if(side == 0 && rayDirX > 0)
		texX = (*texture)->t_w - texX - 1;
	if(side == 1 && rayDirY < 0)
		texX = (*texture)->t_w - texX - 1;
	*place = texX;
	return (lineHeight / 2);
}

int	get_image_pixel(t_image *image, int x, int y)
{
	char				*dst;
	unsigned int		dbl;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
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

void	real_draw(t_fin_map *map, double intersec, int column, t_texture *texture, double place)
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
