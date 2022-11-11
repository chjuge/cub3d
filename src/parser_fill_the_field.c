/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_the_field.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:05:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/11 17:16:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_field	*fill_list(char *str)
{
	int		len;
	int		i;
	t_field	*tmp;
	t_field	*field;

	len = ft_strlen_n(str);
	i = 0;
	field = NULL;
	while (i < len)
	{
		tmp = init_field(str[i]);
		add_back_field(&field, tmp);
		i++;
	}
	return (field);
}

int	fill_the_field(t_map *map, char *str, int fd)
{
	t_list	*tmp;

	while (str && check_for_field(str) == OK)
	{
		printf("str:	'%s'", str);
		tmp = init_list();
		tmp->val = fill_list(str);
		add_back_list(&(map->lst), tmp);
		if (check_first_last_walls(tmp->val))
			break ;
		free(str);
		str = get_next_line(fd);
	}
	if (!str)
		printf("read to end\n");
	else
		return (ERR);
	map->end_flag = 1;
	if (check_first_last_lines(map->lst))
		return (ERR);
	return (OK);
}
