/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 15:18:47 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_fin_map	*prepare_map(int argc, char **argv)
{
	t_map		*map;
	t_fin_map	*res;

	if (check_argc(argc) || check_cub_container(argv[1]))
		exit (1);
	map = init_map();
	if (parse_map(argv[1], map))
		exit (1);
	if (check_for_full_map_full(map) == ERR && container_error(map))
		exit (1);
	read_t_map(map);
	res = copy_to_final(map);
	if (parse_textures(res, map) && container_error2(map, res))
		exit (1);
	free_map(map);
	return (res);
}

void	configure_map(t_fin_map *map)
{
	map->pos_x = (double)map->start_y + 0.5;
	map->pos_y = (double)map->start_x + 0.5;
	map->dir_x = 1.0;
	map->dir_y = 0.0;
	map->planeX = 0.0;
	map->planeY = 0.66;
	if (map->start_dir == NO)
	{
		rotate_vec(&map->dir_x, &map->dir_y, 1.57079632679 * 2.0);
		rotate_vec(&map->planeX, &map->planeY, 1.57079632679 * 2.0);
	}
	else if (map->start_dir == WE)
	{
		rotate_vec(&map->dir_x, &map->dir_y, 1.57079632679);
		rotate_vec(&map->planeX, &map->planeY, 1.57079632679);
	}
	else if (map->start_dir == EA)
	{
		rotate_vec(&map->dir_x, &map->dir_y, -1.57079632679);
		rotate_vec(&map->planeX, &map->planeY, -1.57079632679);
	}
	map->image.image = NULL;
}

int	main(int argc, char **argv)
{
	t_fin_map	*map;

	map = prepare_map(argc, argv);
	configure_map(map);
	printf("hi:%d %d\n", map->start_x, map->start_y);
	map->window = mlx_new_window(map->mlx, WIN_X, WIN_Y, "HELLO");
	draw_frame(map);
	mlx_hook(map->window, 17, 1L << 17, red_button, map);
	mlx_hook(map->window, 4, 1L << 2, manage_mouse, map);
	mlx_hook(map->window, 5, 0, manage_mouse, map);
	mlx_hook(map->window, 2, 1L << 0, manage_key, map);
	mlx_hook(map->window, 6, 1L << 13, manage_move, map);
	mlx_loop(map->mlx);
	return (0);
}
