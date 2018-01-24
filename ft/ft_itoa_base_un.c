/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_un.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:02:53 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/24 19:02:56 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		getbase(char *str, unsigned long long n, int base, int size)
{
	char	*str_base;

	str_base = "0123456789ABCDEF";
	size--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[size--] = str_base[n % base];
		n /= base;
	}
}

static size_t	getsize(unsigned long long n, int base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_un(unsigned long long n, int base)
{
	char				*str;
	size_t				size;

	size = getsize(n, base);
	str = malloc(size + 1);
	str[size] = '\0';
	if (str == NULL)
		return (NULL);
	getbase(str, n, base, size);
	return (str);
}
