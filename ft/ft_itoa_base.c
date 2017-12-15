/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:32:09 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/06 21:26:08 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		getbase(char *str, unsigned long long nb, int base, int size)
{
	char	*str_base;

	str_base = "0123456789ABCDEF";
	size--;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[size--] = str_base[nb % base];
		nb /= base;
	}
}

static size_t	getsize(long long n, unsigned long long *nb,
		int *isnegative, int base)
{
	size_t				size;
	unsigned long long	nb_cpy;

	if (nb == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		*nb = (-n);
		if (base == 10)
			size++;
		*isnegative = 1;
	}
	else
		*nb = n;
	nb_cpy = *nb;
	while (nb_cpy > 0)
	{
		nb_cpy /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(long long n, int base)
{
	unsigned long long	nb;
	char				*str;
	size_t				size;
	int					isnegative;

	isnegative = 0;
	nb = 0;
	size = getsize(n, &nb, &isnegative, base);
	str = malloc(size + 1);
	str[size] = '\0';
	if (str == NULL)
		return (NULL);
	getbase(str, nb, base, size);
	if (isnegative && base == 10)
		str[0] = '-';
	return (str);
}
