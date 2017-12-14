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
INCLUDES	=	libft/includes
SRC			=	\
	ft_printf.c parser.c parser_getstr.c check_exceptions.c crave.c struct_manager.c \
	itoa_base.c itoa_base_un.c ft_getwstr.c
OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ) main.o

fclean: clean
	@rm -rf $(NAME)

f: re
	@gcc main.c $(NAME) $(LIBFT) $(FLAGS) -I $(INCLUDES) -o ft_printf
	@./ft_printf

ff: all
	@gcc main.c $(NAME) $(LIBFT) $(FLAGS) -I $(INCLUDES) -o ft_printf
	@./ft_printf

re: fclean all
