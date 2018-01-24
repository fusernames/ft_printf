# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2018/01/24 19:00:55 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft/libft.a
FLAGS		=	-Wall -Wextra
INCLUDES	=	includes
SRC			=	\
	ft_printf.c \
	lst_manager.c \
	parser.c \
	parse_str.c \
	check_exceptions.c \
	print_specifier.c \
	is.c \
	ft/ft_itoa_base.c \
	ft/ft_itoa_base_un.c \
	ft/ft_getwstr.c \
	ft/ft_atoi.c \
	ft/ft_bzero.c \
	ft/ft_isalpha.c \
	ft/ft_isdigit.c \
	ft/ft_strcmp.c \
	ft/ft_strcpy.c \
	ft/ft_strdup.c \
	ft/ft_strndup.c \
	ft/ft_strlen.c \
	ft/ft_strtolower.c \
	ft/ft_getchar.c \
	ft/ft_strisspace.c \
	ft/ft_putstr.c \
	ft/ft_putchar.c
OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
