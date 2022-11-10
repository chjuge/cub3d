/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_main_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 19:21:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
		printf("Wrong file. It must be [.cub]\n");
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

int	container_error(t_map *map)
{
	printf("map is not full\n");
	printf("map error\n");
	free_map(map);
	return (1);
}

int	container_error2(t_map *map, t_fin_map *res)
{
	printf("wrong path to textures\n");
	free_map(map);
	free_final_map(res);
	return (1);
}
