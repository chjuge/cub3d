# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/10 19:34:44 by mproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

LIBFT = ./libft/libft.a

LIB_INC = ./libft/

MLX_INC = ./mlx/

MLXLIB = ./mlx/libmlx.a

SRCS =	src/parser_color.c\
		src/all_main.c \
		src/all_readers.c \
		src/t_map.c \
		src/t_field.c \
		src/t_list.c \
		src/parser_parser.c \
		src/parser_parser2.c \
		src/parser_parser3.c \
		src/parser_fill_the_field.c\
		src/parser_fill_the_field2.c\
		src/parser_check_for_full_map.c\
		src/parser_fields_to_array.c \
		src/parser_parse_textures.c \
		src/parser_parse_textures2.c \
		src/executer_mlx_hookers.c \
		src/executer_mlx_hookers2.c \
		src/executer_mlx_hookers_containers.c \
		src/executer_draw.c \
		src/parser_free_int_arr.c \
		src/parser_parser_containers.c \
		src/parser_copy_to_final.c \
		src/all_main_utils.c \
		src/executer_trace.c \
		src/executer_real_draw.c


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

%.o:		%.c	 $(HEADER)
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
