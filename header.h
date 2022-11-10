/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:52:20 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/10 12:49:59 by sbrella          ###   ########.fr       */
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
# include <mlx.h>
# define ERR 1
# define OK 0
# define FLOOR 5
# define CEIL 6
# define NO 5
# define SO 6
# define WE 7
# define EA 8
# define WIN_X 1024
# define WIN_Y 720
# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define TOP 65362
#  define BOTTOM 65364
#  define Q 113
#  define W 119
#  define D 100
#  define A 97
#  define S 115
#  define Z 122
#  define X 120
#  define C 99
#  define K 107
#  define L 108
# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define TOP 126
#  define BOTTOM 125
#  define Q 12
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define Z 6
#  define X 7
#  define C 8
#  define K 40
#  define L 37
# endif

typedef struct s_field
{
	struct s_field	*next;
	int				val;
}		t_field;

typedef struct	s_list
{
	struct s_list	*next;
	t_field			*val;
}			t_list;


typedef struct s_map
{
	t_list	*lst;
	char	*path_to_txt_no;
	char	*path_to_txt_so;
	char	*path_to_txt_we;
	char	*path_to_txt_ea;
	int		**map;
	int		color_c;
	int		color_f;
	int		start_x;
	int		start_y;
	int		start_dir;
	int		max_x;
	int		max_y;
} 		t_map;

typedef struct	s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_texture
{
	void	*txtr;
	int		t_w;
	int		t_h;
	t_image	image;
}		t_texture;

typedef struct s_fin_map
{
	t_texture	*texture_no;
	t_texture	*texture_so;
	t_texture	*texture_we;
	t_texture	*texture_ea;
	int		color_c;
	int		color_f;
	int		**map;
	int		start_x;
	int		start_y;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		start_dir;
	void	*mlx;
	void	*window;
	t_image	image;
	int		max_x;
	int		max_y;
}	t_fin_map;

/*		color.c		*/
int	get_color(char *str);
int	color_3_to_1(int r, int g, int b);
int	parse_color(char *str);
int	color_syntax(char *str);

t_map	*init_map();
void	free_map(t_map *map);
void	free_int_arr(int **arr);

int		check_for_color(char *str);
int		check_for_texture(char	*str);
int 	check_for_field(char *str);
int		cmp_with_admissible(char c);
void	add_color_to_map(t_map *map, int flag, char *str);
void	add_texture_to_map(t_map *map, int flag, char *str);

t_field	*fill_list(char *str, t_map *map);
int		fill_the_field(t_map *map, char *str, int fd);

t_field	*init_field(char ch, t_map *map);
t_field *init_field_2(int n);
t_field	*field_last(t_field *lst);
void	add_back_field(t_field **lst, t_field *new);
void	free_fields_all(t_field *t);

t_list	*init_list();
t_list	*list_last(t_list *lst);
void	add_back_list(t_list **lst, t_list *new);
void	free_lists_all(t_list *t);

int	parse_map(char *param, t_map *map);


void	fields_to_array(t_map *map);


int	check_for_full_map(t_map *map);

void	read_int_map(int **map, int max_x, int max_y);
void	read_t_map(t_map *map);

void	read_lines(t_list	*lst);

int	parse_textures(t_fin_map *fin, t_map *map);

void	free_final_map(t_fin_map *map);

int		manage_move(int x, int y, void *param);
int		manage_key(int keycode, void *param);
int		manage_mouse(int button, int x, int y, void *param);
int		red_button(void *param);
void	draw_frame(t_fin_map *map);
void	rotate_vec(double *x, double *y, double angle);
#endif
