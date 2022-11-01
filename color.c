/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:53:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 14:54:14 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_color(char *str)
{
	int	len;
	int	i;
	int	res;

	i = 0;
	len = ft_strlen(str);
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
	char	**colors;

	colors = ft_split(str, ',');
}