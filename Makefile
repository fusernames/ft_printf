# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2017/12/04 21:50:27 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft/libft.a
FLAGS		=	-Wall -Wextra
INCLUDES	=	includes
SRC			=	\
	ft_printf.c \
	parser.c \
	parser_getstr.c \
	check_exceptions.c \
	crave.c \
	struct_manager.c \
	ft/ft_itoa_base.c \
	ft/ft_itoa_base_un.c \
	ft/ft_getwstr.c \
	ft/ft_atoi.c \
	ft/ft_bzero.c \
	ft/ft_isalpha.c \
	ft/ft_isdigit.c \
	ft/ft_memmove.c \
	ft/ft_strcmp.c \
	ft/ft_strcpy.c \
	ft/ft_strdup.c \
	ft/ft_strlen.c \
	ft/ft_strtolower.c \
	ft/ft_getchar.c \
	ft/ft_strisspace.c
OBJ			=	$(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj/%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ) main.o

fclean: clean
	@rm -rf $(NAME)

f: re
	@gcc main.c $(NAME) $(FLAGS) -I $(INCLUDES) -o ft_printf
	@./ft_printf

ff: all
	@gcc main.c $(NAME) $(FLAGS) -I $(INCLUDES) -o ft_printf
	@./ft_printf

re: fclean all
