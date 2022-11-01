/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 18:50:29 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_for_color(char *str)
{
	int	i;

	if (!str || ft_strlen_n(str) < 8)
		return (ERR);
	if (str[0] != 'F' || str[0] != 'C')
		return (ERR);
	if (str[1] != ' ')
		return (ERR);
	if (!ft_isnum(str[2]))
		return (ERR);
	i = 3;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isnum(str[i]) || str[i] != ',')
			return (ERR);
		i++;
	}
	if (str[0] == 'F')
		return (FLOOR);
	return (CEIL);
}

// int	check_for_texture(char	*str)
// {
// 	return (OK);
// }

// void	add_texture_to_map(t_map *map, int flag, char *str)
// {
// 	return (OK);
// }

void	add_color_to_map(t_map *map, int flag, char *str)
{
	if (flag == CEIL)
		map->color_c = get_color(str + 2);
	else if (flag == FLOOR)
		map->color_f = get_color(str + 2);
}

int	parse_map(char *param, t_map *map)
{
	int		fd;
	char	*str;
	int 	flag;

	fd = open(param, O_RDONLY);
	if (fd < 0)
		return (ERR);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		flag = check_for_color(str);
		if (flag != ERR)
			add_color_to_map(map, flag, str);
		// flag = check_for_texture(str); //todo
		// if (flag != ERR)
		// 	add_texture_to_map(map, flag, str); //todo
		// flag = check_for_field(str); //todo
		// if (flag != ERR)
		// 	fill_the_field();//todo
		free(str);
	}
	return (OK);
}
