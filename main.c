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
	wchar_t		c;

	c = 65;
	setlocale(LC_ALL, "");
	printf("|retour pf : %d|\n", printf("%.*d\n", 10, c));
	ft_printf("|retour ft : %d|\n", ft_printf("%.*d\n", 10, c));
	return (0);
}
