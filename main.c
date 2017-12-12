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

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	//wchar_t	c;
	//c = 4660;
	//printf("%d\n", MB_CUR_MAX);
	setlocale(LC_ALL, "");
	//printf("%d\n", MB_CUR_MAX);
	//printf("printf : %lc\n", c);
	//printf("|retour : %d|\n", printf("%C\n", c));
	//ft_printf("|retour : %d|\n", ft_printf("%C\n", c));
	ft_printf("salut %0*.*d, %.*d\n", 120, 20, 999999, 359, 15);
	return (0);
}
