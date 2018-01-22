/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:56:53 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/22 21:29:58 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *s)
{
	int		is_negative;
	int		nb;

	nb = 0;
	is_negative = 0;
	while (ft_isspace(*s))
		s++;
	if (!ft_strcmp("-2147483648", s))
		return (-2147483648);
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		is_negative = 1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nb = (nb * 10) + *s - '0';
		s++;
	}
	return (is_negative ? -nb : nb);
}
