/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:53:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/05 20:13:47 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_color(char *str)
{
	int	len;
	int	i;
	int	res;

	if (!str)
		return (-ERR);
	if (color_syntax(str) == ERR)
		return (-ERR);
	i = 0;
	len = ft_strlen_n(str);
	res = 0;
	while (len > 2)
	{
		if (ft_isalpha(str[len - 1]))
			res += (ft_tolower(str[len - 1]) - 87) * pow(16, i);
		else
			res += (str[len - 1] - '0') * pow(16, i);
		len--;
		i++;
	}
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
	free_char_array(clrs);
	if (r == -ERR || g == -ERR || b == -ERR)
		return (-ERR);
	return (color_3_to_1(r, g, b));
}

int	color_syntax(char *str)
{
	int	i;

	if (!str)
		return (ERR);
	printf("%s\n", str);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isalnum(str[i]) && str[i] != ',')
			return (ERR);
		i++;
	}
	return (OK);
}