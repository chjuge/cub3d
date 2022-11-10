/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:53:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 13:19:07 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_color(char *str)
{
	int	res;

	if (!str)
		return (-ERR);
	if (color_syntax(str) == ERR)
		return (-ERR);
	res = ft_atoi(str);
	printf("my int: %d\n", res);
	if (res > 255 || res < 0)
		return (-ERR);
	return (res);
}

int	color_3_to_1(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	parse_color(char *str)
{
	char	**clrs;
	int		r;
	int		g;
	int		b;

	if (!str)
		return (-ERR);
	clrs = ft_split(str, ',');
	r = get_color(clrs[0]);
	g = get_color(clrs[1]);
	b = get_color(clrs[2]);
	if (clrs[3] && clrs[3] != NULL)
	{
		free_char_array(clrs);
		return (-ERR);
	}
	free_char_array(clrs);
	if (r == -ERR || g == -ERR || b == -ERR)
		return (-ERR);
	return (color_3_to_1(r, g, b));
}

int	color_syntax(char *str)
{
	int	i;

	if (!str || str[0] == '\n' || str[0] == '\0')
		return (ERR);
	printf("%s\n", str);
	i = 0;
	if (ft_strlen_n(str) > 3)
		return (ERR);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isalnum(str[i]))
			return (ERR);
		i++;
	}
	return (OK);
}
