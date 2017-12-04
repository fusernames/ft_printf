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

#include "ft_printf.h"

static int	check_flags(t_spe *elem)
{
	if (elem->zero && elem->less)
		elem->zero = 0;
	return (1);
}

int			check_exceptions(t_spe *start)
{
	while (start)
	{
		check_flags(start);
		start = start->next;
	}
	return (1);
}
