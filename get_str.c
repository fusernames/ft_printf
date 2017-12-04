/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:12:25 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/04 22:56:49 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_str(va_list ap, t_spe *start)
{
	char *spe;
	while (start)
	{
		spe = start->specifier;
		if (!ft_strcmp(spe, "s"))
			start->s = va_arg(ap, char*);
		else if (!ft_strcmp(spe, "d"))
			start->s = itoa_base(va_arg(ap, int), 10);
		else if (!ft_strcmp(spe, "ld"))
			start->s = itoa_base(va_arg(ap, long), 10);
		else if (!ft_strcmp(spe, "X"))
			start->s = itoa_base(va_arg(ap, int), 16);
		else
			start->s = itoa_base(va_arg(ap, int), 10);
		start = start->next;
	}
}
