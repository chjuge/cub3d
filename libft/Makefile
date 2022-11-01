# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 18:42:35 by mproveme          #+#    #+#              #
#    Updated: 2022/11/01 17:21:56 by mproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrstr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strcpy.c \
		get_next_line.c \
		get_next_line_utils.c \
		get_next_line_utils2.c \
		ft_free_char_array.c \
		ft_isnum.c
		

OBJ		= 	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	./libft.h

all:		$(NAME)

%.o:		%.c	$(HEADER) 
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HEADER)
			ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) 

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 