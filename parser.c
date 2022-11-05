/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:43:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 20:10:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_for_color(char *str)
{
	int	i;

	if (!str || ft_strlen_n(str) < 8)
		return (ERR);
	if (str[0] != 'F' && str[0] != 'C')
		return (ERR);
	if (str[1] != ' ')
		return (ERR);
	if (!ft_isnum(str[2]))
		return (ERR);
	i = 3;
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

void	add_texture_to_map(t_map *map, int flag, char *str)
{
	if (flag == NO)
		map->texture_no = ft_strdup_n(str + 3);
	else if (flag == SO)
		map->texture_so = ft_strdup_n(str + 3);
	else if (flag == WE)
		map->texture_we = ft_strdup_n(str + 3);
	else if (flag == EA)
		map->texture_ea = ft_strdup_n(str + 3);
}

void	add_color_to_map(t_map *map, int flag, char *str)
{
	if (flag == CEIL)
		map->color_c = get_color(str + 2);
	else if (flag == FLOOR)
		map->color_f = get_color(str + 2);
}

int cmp_with_admissible(char c)
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

int check_for_field(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ERR);
	while (str[i] && str[i] != '\n')
	{
		if (cmp_with_admissible(str[i]) == ERR)
		{
			return (ERR);
		}
		i++;
	}
	return (OK);
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
		if (ft_strncmp("\n", str, 2) == 0)
		{
			free(str);
			// str = NULL;
			printf("\\n\n");
			continue ;
		}
		flag = check_for_color(str);
		if (flag != ERR)
		{
			printf("got color\n");
			add_color_to_map(map, flag, str);
			free(str);
			// str = NULL;
			continue ;
		}
		flag = check_for_texture(str);
		if (flag != ERR)
		{
			printf("got texture\n");
			add_texture_to_map(map, flag, str);
			free(str);
			// str = NULL;
			continue;
		}
		flag = check_for_field(str);
		if (flag != ERR)
		{
			printf ("got field\n");
			if 	(fill_the_field(map, str, fd) == ERR)
			{
				printf("map error\n");
				free_map(map);
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
		else
		{
			printf("got bad line:\n%s\n", str);
			printf("map error\n");
			close(fd);
			free_map(map);
			free(str);
			return (ERR);
		}
	}
	return (OK);
}
