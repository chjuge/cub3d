# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/01 14:20:45 by mproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	map_parser

LIBFT = libft.a

SRCS =	color.c\
		main.c

OBJ	= 	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	./libft.h

all:		libft	$(NAME)

libft:		
			make -C libft

%.o:		%.c	$(HEADER) 
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HEADER)
			ar rc $(NAME) $(OUT)

clean:
		make -C libft/ clean
		rm -f $(OBJ) 

fclean:	clean
		make -C libft/ fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 