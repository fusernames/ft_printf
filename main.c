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
	wchar_t		c[3];

	c[0] = 65;
	c[1] = 4660;
	c[2] = 0;
	setlocale(LC_ALL, "");
	printf("|retour pf : %d|\n", printf("%020ls", c));
	ft_printf("|retour ft : %d|\n", ft_printf("%020ls", c));
	return (0);
}
