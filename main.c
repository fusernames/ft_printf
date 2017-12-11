/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:31 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/07 20:19:39 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	wchar_t	c;
	c = 182;
	//printf("%zu\n", MB_CUR_MAX);
	setlocale(LC_ALL, "");
	//printf("printf : %lc\n", c);
	printf("|retour : %d|\n", printf("%C\n", c));
	ft_printf("|retour : %d|\n", ft_printf("%C\n", c));
	return (0);
}
