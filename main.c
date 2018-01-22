/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:31 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/22 21:27:15 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("|retour pf : %d|\n", printf("%hU", 4294967295));
	printf("|retour ft : %d|\n", ft_printf("%hU", 4294967295));
	return (0);
}
