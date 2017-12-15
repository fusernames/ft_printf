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

static int	check_flags(t_spe *elem)
{
	char	c;
	c = elem->specifier;
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
		if (c != 'p' || !ft_strcmp(elem->s, "(nil)"))
			elem->hash = 0;
		else
			elem->hash = 1;
	}
	if (elem->plus)
		elem->space = 0;
	if (elem->less)
		elem->zero = 0;
	if (elem->width > 0 && elem->zero)
	{
		elem->precision = elem->width;
		elem->width = 0;
		elem->zero = 0;
	}
	if (elem->s[0] == '-')
	{
		elem->plus = 0;
		elem->space = 0;
	}
	return (1);
}

int			check_exceptions(t_spe *start)
{
	while (start)
	{
		check_flags(start);
		//check_specifier(start);
		start = start->next;
	}
	return (1);
}
