/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:59:38 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 14:28:04 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*next_line;

	if (fd < 0 || fd > 256 || read(fd, NULL, 0) < 0)
		return (0);
	if (remainder)
	{
		if ((find_end_of_line(remainder)) != -1)
		{
			next_line = cut_from_remainder(&remainder);
			return (next_line);
		}
		if ((read_file(&remainder, fd)) || remainder[0] != '\0')
		{
			next_line = cut_from_remainder(&remainder);
			return (next_line);
		}
		free(remainder);
	}
	if ((read_file(&remainder, fd)))
	{
		next_line = cut_from_remainder(&remainder);
		return (next_line);
	}
	return (0);
}
