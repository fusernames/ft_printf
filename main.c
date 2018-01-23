/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:31 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/23 20:14:17 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("|retour pf : %d|\n", printf("%15.4d", -424242));
	printf("|retour ft : %d|\n", ft_printf("%15.4d", -424242));
	return (0);
}
