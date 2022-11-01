/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:57:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 14:28:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_new_remainder(char *old_rem, char *buf, int buf_len)
{
	char	*new_rem;
	int		len_old_rem;
	int		len_new_rem;

	len_old_rem = ft_strlen(old_rem);
	len_new_rem = len_old_rem + buf_len;
	new_rem = malloc(len_new_rem + 1);
	if (!new_rem)
		return (0);
	if (len_old_rem)
		ft_memcpy(new_rem, old_rem, len_old_rem);
	ft_memcpy(new_rem + len_old_rem, buf, buf_len);
	new_rem[len_new_rem] = '\0';
	free(old_rem);
	return (new_rem);
}

char	*cut_from_remainder(char **old_rem)
{
	int		len_old_rem;
	int		len_new_rem;
	int		len_next_line;
	char	*next_line;
	char	*new_rem;

	len_old_rem = ft_strlen(*old_rem);
	len_next_line = find_len_next_line(*old_rem) + 1;
	len_new_rem = len_old_rem - len_next_line;
	next_line = malloc(len_next_line + 1);
	ft_memcpy(next_line, *old_rem, len_next_line);
	next_line[len_next_line] = '\0';
	new_rem = malloc(len_new_rem + 1);
	ft_memcpy(new_rem, (*old_rem) + len_next_line, len_new_rem);
	new_rem[len_new_rem] = '\0';
	free(*old_rem);
	*old_rem = new_rem;
	return (next_line);
}

int	read_file(char **remainder, int fd)
{
	char	*buf;
	int		buf_len;
	int		check_end;
	int		count;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	check_end = -1;
	count = 0;
	buf_len = read(fd, buf, BUFFER_SIZE);
	buf[buf_len] = '\0';
	while (buf_len && check_end == -1)
	{
		check_end = find_end_of_line(buf);
		*remainder = create_new_remainder(*remainder, buf, buf_len);
		if (check_end < 0)
			buf_len = read(fd, buf, BUFFER_SIZE);
		count++;
	}
	free(buf);
	return (count);
}
