# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/10 15:00:50 by mproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

LIBFT = ./libft/libft.a

LIB_INC = ./libft/

MLX_INC = ./mlx/

MLXLIB = ./mlx/libmlx.a

SRCS =	parser_color.c\
		all_main.c \
		all_readers.c \
		t_map.c \
		t_field.c \
		t_list.c \
		parser_parser.c \
		parser_parser2.c \
		parser_parser3.c \
		parser_fill_the_field.c\
		parser_check_for_full_map.c\
		parser_fields_to_array.c \
		parser_parse_textures.c \
		parser_parse_textures2.c \
		executer_mlx_hookers.c \
		executer_draw.c \
		parser_free_int_arr.c \
		parser_parser_containers.c


OBJ	= 	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	header.h

all:		libft mlx $(NAME)

libft:
			make -C libft/

mlx:
			make -C mlx/

# mlx:
# 			make -C mlx_linux/

%.o:		%.c	$(HEADER)
			$(CC) $(FLAGS) -Imlx -c $< -o $@
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -I $(LIB_INC) $(LIBFT)
# -Imlx
$(NAME):	$(OBJ) $(HEADER) $(mlx)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit


cl:		
		rm $(OBJ)


clean:
		make -C libft/ clean
		make -C mlx/ clean
		rm -f $(OBJ)

fclean:	clean
		make -C libft/ fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re libft mlx cl
