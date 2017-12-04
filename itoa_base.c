/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:32:09 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/04 21:06:43 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		getbase(char *str, long long unsigned nb, int base, int size)
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

static size_t	getsize(long long n, long long unsigned *nb,
		int *isnegative, int base)
{
	size_t				size;
	long long unsigned	nb_cpy;

	if (nb == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		*nb = (-n);
		if (base == 10)
		{
			*isnegative = 1;
			size++;
		}
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

char			*itoa_base(long long n, int base)
{
	long long unsigned	nb;
	char				*str;
	size_t				size;
	int					isnegative;

	isnegative = 0;
	nb = 0;
	size = getsize(n, &nb, &isnegative, base);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	getbase(str, nb, base, size);
	if (isnegative)
		str[0] = '-';
	return (str);
}
