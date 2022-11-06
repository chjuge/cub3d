# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/06 12:01:36 by mproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	map_parser

LIBFT = ./libft/libft.a

LIB_INC = ./libft/

MLX_INC = ./mlx/

MLXLIB = ./mlx/libmlx.a

SRCS =	color.c\
		main.c \
		utils.c \
		parser.c \
		t_map.c \
		fill_the_field.c\
		t_field.c \
		t_list.c \
		check_for_full_map.c\
		fields_to_array.c \
		f_readers.c \
		parse_textures.c


OBJ	= 	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	header.h

all:		libft mlx $(NAME)

libft:		
			make -C libft/

mlx:			
			make -C mlx/

%.o:		%.c	$(HEADER) 
			$(CC) $(FLAGS) -Imlx -c $< -o $@
# -Imlx
$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
# -Lmlx -lmlx -framework OpenGL -framework AppKit

clean:
		make -C libft/ clean
		make -C mlx/ clean
		rm -f $(OBJ) 

fclean:	clean
		make -C libft/ fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re libft mlx
