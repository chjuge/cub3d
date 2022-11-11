/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parser2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 13:58:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_for_color(char *str)
{
	int	i;

	if (!str || ft_strlen_n(str) < 8)
		return (ERR);
	if (str[0] != 'F' && str[0] != 'C')
		return (ERR);
	if (str[1] != ' ')
		return (ERR);
	i = 2;
	while (str[i] == ' ')
		i++;
	if (!ft_isnum(str[i]))
		return (ERR);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isnum(str[i]) && str[i] != ',')
			return (ERR);
		i++;
	}
	if (str[0] == 'F')
		return (FLOOR);
	return (CEIL);
}

int	check_for_texture(char	*str)
{
	if (!str || ft_strlen_n(str) < 4)
		return (ERR);
	if (ft_strncmp("SO ", str, 3) == 0)
		return (SO);
	if (ft_strncmp("NO ", str, 3) == 0)
		return (NO);
	if (ft_strncmp("WE ", str, 3) == 0)
		return (WE);
	if (ft_strncmp("EA ", str, 3) == 0)
		return (EA);
	return (ERR);
}

void	add_texture_to_map(t_map *map, int flag, char *str_r)
{
	char	*str;

	str = str_r + 3;
	while (*str == ' ')
		str++;
	if (flag == NO && !(map->path_to_txt_no))
		map->path_to_txt_no = ft_strdup_n(str);
	else if (flag == SO && !(map->path_to_txt_so))
		map->path_to_txt_so = ft_strdup_n(str);
	else if (flag == WE && !(map->path_to_txt_we))
		map->path_to_txt_we = ft_strdup_n(str);
	else if (flag == EA && !(map->path_to_txt_ea))
		map->path_to_txt_ea = ft_strdup_n(str);
}

void	add_color_to_map(t_map *map, int flag, char *str)
{
	int	i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (flag == CEIL && map->color_c == -1)
		map->color_c = parse_color(str + i);
	else if (flag == FLOOR && map->color_f == -1)
		map->color_f = parse_color(str + i);
}

int	cmp_with_admissible(char c)
{
	if (c == ' ')
		return (OK);
	if (c == '1')
		return (OK);
	if (c == '0')
		return (OK);
	if (c == 'N')
		return (OK);
	if (c == 'S')
		return (OK);
	if (c == 'W')
		return (OK);
	if (c == 'E')
		return (OK);
	return (ERR);
}
