/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_real_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:16:43 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 15:18:26 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	image_pixel(t_image *image, int color, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_clamp(int ret, int fringe)
{
	if (ret >= fringe)
		ret = fringe - 1;
	return (ret);
}

void	real_draw(t_fin_map *map, int column,
		t_texture *texture, t_inter i)
{
	int	upper_fr;
	int	lower_fr;
	int	count;
	int	tex_color;

	count = 0;
	upper_fr = WIN_Y / 2 - (int)i.intersec;
	lower_fr = WIN_Y / 2 + (int)i.intersec;
	while (count < WIN_Y)
	{
		if (count < upper_fr)
			image_pixel(&map->image, map->color_c, column, count);
		else if (count > lower_fr)
			image_pixel(&map->image, map->color_f, column, count);
		else
		{
			tex_color = get_image_pixel(&texture->image, (int)i.place,
					ft_clamp(((count - upper_fr) * texture->t_h)
						/ (2 * (int)i.intersec), texture->t_h));
			image_pixel(&map->image, tex_color, column, count);
		}
		count++;
	}
}
