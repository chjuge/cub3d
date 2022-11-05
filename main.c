/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:45 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 18:51:37 by mproveme         ###   ########.fr       */
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
		read_t_map(map);
		free_map(map);
	}
	return (0);
}
