/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:52:20 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/01 18:56:08 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
// # include <mlx.h>
# define ERR 1
# define OK 0
# define FLOOR 5
# define CEIL 6
# define NO 5
# define SO 6
# define WE 7
# define EA 8

typedef struct s_map
{
	void	*texture_no;
	void	*texture_so;
	void	*texture_we;
	void	*texture_ea;
	int		color_c;
	int		color_f;
	int		**map;
	int		star_x;
	int		start_y;
	int		start_dir;
} 		t_map;




/*		color.c		*/
int	get_color(char *str);
int	color_3_to_1(int r, int g, int b);
int	parse_color(char *str);
int	color_syntax(char *str);
#endif