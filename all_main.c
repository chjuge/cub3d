/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 14:06:22 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (ERR);
	if (str[len - 1] != 'b')
		return (ERR);
	if (str[len - 2] != 'u')
		return (ERR);
	if (str[len - 3] != 'c')
		return (ERR);
	if (str[len - 4] != '.')
		return (ERR);
	return (OK);
}

int	check_cub_container(char *str)
{
	int	res;

	res = check_cub(str);
	if (res)
		printf("Wrong file. It must bu [.cub]\n");
	return (res);
}

int	check_argc(int argc)
{
	if (argc != 2)
	{
		printf("Wrong number of arguments\n");
		return (ERR);
	}
	return (OK);
}

t_fin_map	*copy_to_final(t_map *map)
{
	t_fin_map	*res;

	res = malloc(sizeof(t_fin_map));
	res->texture_ea = malloc(sizeof(t_texture));
	res->texture_no = malloc(sizeof(t_texture));
	res->texture_so = malloc(sizeof(t_texture));
	res->texture_we = malloc(sizeof(t_texture));
	res->color_c = map->color_c;
	res->color_f = map->color_f;
	res->map = map->map;
	res->start_x = map->start_x;
	res->start_y = map->start_y;
	res->start_dir = map->start_dir;
	res->max_x = map->max_x;
	res->max_y = map->max_y;

	return(res);
}

t_fin_map *prepare_map(int argc, char **argv)
{
	t_map		*map;
	t_fin_map	*res;

	if (check_argc(argc) || check_cub_container(argv[1]))
		exit (1);
	map = init_map();
	if (parse_map(argv[1], map) != ERR)
	{
		if (check_for_full_map(map) == ERR)
		{
			printf("map is not full\n");
			printf("map error\n");
			free_map(map);
			exit (1);
		}
	}
	read_t_map(map);
	res = copy_to_final(map);
	if (parse_textures(res, map) == ERR)
	{
		printf("wrong path to textures\n");
		free_map(map);
		// free_final_map(res);
		// return (NULL);
	}
	else
	{
		printf("got textures!\n");
	}
	free_map(map);
	return (res);
}

void	configure_map(t_fin_map *map)
{
	// map->posX = (double)map->start_x + 0.5; 
	// map->posY = (double)map->start_y + 0.5;
	map->posX = 1.5;
	map->posY = 2.5;
	map->dirX = 1.0;
	map->dirY = 0.0; //initial direction vector
	map->planeX = 0.0;
	map->planeY = 0.66; //the 2d raycaster version of camera plane
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
	mlx_hook(map->window, 4, 1L<<2, manage_mouse, map);
	mlx_hook(map->window, 5, 0, manage_mouse, map);
	mlx_hook(map->window, 2, 1L<<0, manage_key, map);
	mlx_hook(map->window, 6, 1L<<13, manage_move, map);
	mlx_loop(map->mlx);
	return (0);
}
