/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:31 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:55:23 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(void)
{
	//setlocale(LC_ALL, "");
	printf("|retour pf : %d|\n", printf("toto %###.0o%#.o et %#.1o !", 0, 0, 0));
	printf("|retour pf : %d|\n", ft_printf("toto %###.0O%#.O et %#.1O !", 0, 0, 0));
	return (0);
}
