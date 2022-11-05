/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 20:16:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	map = init_map();
	if (parse_map(argv[1], map) != ERR)
	{
		// if (check_for_full_map(map) == ERR)
		// {
		// 	printf("map is not full\n");
		// 	printf("map error\n");
		// 	free_map(map);
		// 	return (ERR);
		// }
		read_t_map(map);
		free_map(map);
		printf("%d\n", 0xdc6400); // 220,100,0
	}
	return (0);
}
