/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parser_containers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 15:03:41 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	container_cannot_open(int fd, char *param)
{
	printf("cannot open:	%s\n", param);
	close(fd);
	return (ERR);
}

int	container_check_new_line(char *str)
{
	if (ft_strncmp("\n", str, 2) == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	container_check_for_color(t_map *map, int *flag, char *str)
{
	*flag = check_for_color(str);
	if (*flag != ERR)
	{
		add_color_to_map(map, *flag, str);
		free(str);
		return (1);
	}
	return (0);
}

int	container_check_for_texture(t_map *map, int *flag, char *str)
{
	*flag = check_for_texture(str);
	if (*flag != ERR)
	{
		add_texture_to_map(map, *flag, str);
		free(str);
		return (1);
	}
	return (0);
}

int	container_check_for_field(t_map *map, int *flag, char *str, int fd)
{
	*flag = check_for_field(str);
	if (*flag != ERR)
	{
		printf ("got field\n");
		if (fill_the_field(map, str, fd) == ERR)
		{
			printf("map error\n");
			close(fd);
			return (ERR);
		}
		else
		{
			fields_to_array(map);
			close(fd);
			return (OK);
		}
	}
	return (ERR);
}
