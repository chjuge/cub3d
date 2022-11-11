/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 19:40:03 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_free(t_map *map, char *str)
{
	if (map->end_flag == 0)
		free(str);
	return (1);
}

int	parse_map(char *param, t_map *map)
{
	int		fd;
	char	*str;
	int		flag;

	fd = open(param, O_RDONLY);
	if (fd < 0 && container_cannot_open(fd, param))
		return (ERR);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (container_check_new_line(str))
			continue ;
		if (container_check_for_color(map, &flag, str))
			continue ;
		if (container_check_for_texture(map, &flag, str))
			continue ;
		if (container_check_for_field(map, &flag, str, fd) != ERR)
			return (OK);
		else if (check_free(map, str))
			return (ERR);
	}
	return (OK);
}
