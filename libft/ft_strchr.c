/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:24:25 by sbrella           #+#    #+#             */
/*   Updated: 2021/11/23 19:05:42 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a] != (char)c)
	{
		if (s[a] == '\0')
			return (0);
		a++;
	}
	return ((char *)&s[a]);
}
