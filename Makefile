# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/09 12:15:42 by ilya             ###   ########.fr        #
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
		parse_textures.c \
		mlx_hookers.c \
		draw.c


OBJ	= 	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	header.h

all:		libft mlx $(NAME)

libft:
			make -C libft/

# mlx:
# 			make -C mlx/

mlx:
			make -C mlx_linux/

# %.o:		%.c	$(HEADER)
# 			$(CC) $(FLAGS) -Imlx -c $< -o $@
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -I $(LIB_INC) $(LIBFT)
# -Imlx
# $(NAME):	$(OBJ) $(HEADER)
# 			$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
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
