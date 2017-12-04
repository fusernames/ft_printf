/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:24:10 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/04 23:23:40 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 1. Parser les % dans une liste
 * 2. Checker les exceptions de la liste
 * 3. Remplir le champs *str de chaque element
 * 4. Produire la str finale
 */

static void	print_str(const char *format, t_spe *start)
{
	char	buf[4096];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			while (!is_specifier(format[i]) && format[i])
				i++;
			i++;
			while (start->s[k])
				buf[j++] = start->s[k++];
			start = start->next;
			k = 0;
		}
		else if (format[i] == '%' && format[i] == '%')
			i++;
		if (!format[i])
			break ; 
		buf[j++] = format[i++];
	}
	buf[j] = '\0';
	ft_putstr(buf);
}

int				ft_printf(const char *format, ...)
{
	t_spe	*start;
	//t_spe	*elem;
	va_list ap;

	start = NULL;
	if (parser(format, &start) == -1)
		return(1);
	check_exceptions(start);
	va_start(ap, format);
	get_str(ap, start);
	print_str(format, start);
	while (start)
	{
		printf("specifier\t-> %s\n", start->specifier);
		printf("width\t\t-> %d\n", start->width);
		printf("precision\t-> %d\n", start->precision);
		printf("\n");
		start = start->next;
	}
	va_end(ap);
	return (0);
}
