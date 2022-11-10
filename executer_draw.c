/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:41:50 by ilya              #+#    #+#             */
/*   Updated: 2022/11/10 18:44:41 by mproveme         ###   ########.fr       */
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

int	get_image_pixel(t_image *image, int x, int y)
{
	char			*dst;
	unsigned int	dbl;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	if (image->endian == 0)
	{
		dbl = *(unsigned int *)dst;
		dbl = (dbl & 0x00FFFFFF);
		return (dbl);
	}
	return (*dst);
}

void	draw_column(t_fin_map *map, int column)
{
	int			intersec;
	t_texture	*texture;
	double		place;
	t_inter		inter;

	intersec = trace(column, map, &texture, &place);
	inter.intersec = intersec;
	inter.place = place;
	real_draw(map, column, texture, inter);
}

void	draw_frame(t_fin_map *map)
{
	int		count;
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
