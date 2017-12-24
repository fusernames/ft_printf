/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:31 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/24 12:04:45 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(void)
{
	int	s[5] = {'S', 4660, 'u', 'a', 0};
	setlocale(LC_ALL, "");
	//printf("|retour pf : %d|\n", printf("%8C et coco %C %lc", 3250, 0x11ffff, 'a'));
	//printf("|retour ft : %d|\n", ft_printf("%8C et coco %C %lc", 3250, 0x11ffff, 'a'));
	printf("|retour pf : %d|\n", printf("hey %s %.2ls", "salut", s));
	printf("|retour ft : %d|\n", ft_printf("hey %s %.2ls", "salut", s));
	return (0);
}
