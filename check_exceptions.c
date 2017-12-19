/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exceptions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:24:51 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/03 17:43:29 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	flags_vs_flags(t_spe *elem)
{
	if (elem->precision > -1)
		elem->zero = 0;
	if (elem->plus)
		elem->space = 0;
	if (elem->minus)
		elem->zero = 0;
}

static void	flags_vs_str(t_spe *elem)
{
	char	c;

	c = elem->spe;
	if (elem->s && elem->s[0] == '-')
	{
		elem->plus = 0;
		elem->space = 0;
	}
	if (!ft_strcmp("0", elem->s))
		elem->hash = 0;
	if (c == 'p' && !ft_strcmp("(nil)", elem->s))
		elem->hash = 0;
}

static void	flags_vs_specifiers(t_spe *elem)
{
	char	c;
	c = elem->spe;
	if (c == 'x' || c == 'X' || c == 'o')
	{
		elem->space = 0;
		elem->plus = 0;
	}
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
		elem->hash = 0;
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p')
	{
		elem->plus = 0;
		elem->zero = 0;
		elem->space = 0;
		elem->precision = -1;
		if (c != 'p' || !elem->s)
			elem->hash = 0;
		else
			elem->hash = 1;
	}
}

int			check_exceptions(t_spe *start)
{
	while (start)
	{
		flags_vs_flags(start);
		flags_vs_specifiers(start);
		flags_vs_str(start);
		//check_specifier(start);
		start = start->next;
	}
	return (1);
}
