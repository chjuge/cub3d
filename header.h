/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:52:20 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 14:54:43 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <math.h>
# define ERR 1
# define OK 0

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*we;
	int		f;
	int		c;
	
} 		t_map;


/*		color.c		*/
int	get_color(char *str);
int	color_3_to_1(int r, int g, int b);

#endif