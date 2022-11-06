/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 12:46:22 by mproveme         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_map	*map;

	if (check_argc(argc) || check_cub_container(argv[1]))
		return (1);
	map = init_map();
	if (parse_map(argv[1], map) != ERR)
	{
		if (check_for_full_map(map) == ERR)
		{
			printf("map is not full\n");
			printf("map error\n");
			free_map(map);
			return (ERR);
		}
		read_t_map(map);
		if (parse_textures(map) == ERR)
		{
			printf("wrong path to textures\n");
			// free_map(map);
			// return (NULL);
		}
		else
			printf("got textures!\n");
	}
	free_map(map); //
	return (0);    //
	// return (map);
}
