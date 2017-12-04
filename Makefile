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

NAME		=	ft_printf
LIBFT		=	libft/libft.a
FLAGS		=	-Wall -Wextra
INCLUDES	=	libft/includes
SRC			=	$(wildcard *.c)
OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME) -I $(INCLUDES)

%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

f: re
	@./$(NAME)

re: fclean all
