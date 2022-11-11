/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 13:39:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	got_bad_line(char *str, int fd)
{
	printf("got bad line:\n%s\n", str);
	printf("map error\n");
	close(fd);
	printf("out of got_bad_line\n");
	return (1);
}

int	container_free_str(char *str)
{
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
		else if (container_free_str(str))
			break ;
	}
	got_bad_line(str, fd);
	return (ERR);
}
