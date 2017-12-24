/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:24:10 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/24 12:06:39 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * 1. Parser les % dans une liste
 * 2. Checker les exceptions de la liste
 * 3. Remplir le champs *str de chaque element
 * 4. Produire la str finale
 */

static int		print_str(char *fmt, va_list *ap, t_spe **start)
{
	int		i;
	int		ret;
	t_spe		*elem;

	i = 0;
	ret = 0;
	elem = NULL;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if ((elem = parser(&fmt[i + 1], ap, start)) == NULL)
				return (-1);
			check_exceptions(elem);
			if (elem->error)
				return (-1);
			while (!is_specifier(fmt[i]) && fmt[i])
				i++;
			i++;
			ret += print_specifier(elem);
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			i++;
			ret += ft_putchar(fmt[i++]);
		}
		else if (fmt[i])
			ret += ft_putchar(fmt[i++]);
	}
	return(ret);
}

int				ft_printf(const char *format, ...)
{
	t_spe	*start;
	va_list ap;
	int	ret;

	start = NULL;
	va_start(ap, format);
	ret = print_str((char *)format, &ap, &start);
	va_end(ap);
	lst_del(start);
	return (ret);
	/*while (start)
	{
		printf("\nspecifier\t-> %c\n", start->spe);
		printf("conv\t\t-> %s\n", start->conv);
		printf("+\t\t-> %d\n", start->plus);
		printf("width\t\t-> %ld\n", start->width);
		printf("precision\t-> %ld\n", start->precision);
		printf("str\t\t-> %s\n", start->s);
		printf("error\t\t-> %d\n", start->error);
		printf("\n");
		start = start->next;
	}*/
}
