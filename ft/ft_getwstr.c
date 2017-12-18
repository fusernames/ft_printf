/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:03 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/11 19:25:17 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	check_mbcurmax(wchar_t c, t_spe *e)
{
	if (c < 0)
		e->error = 1;
	if (c >= 128 && MB_CUR_MAX < 2)
		e->error = 1;
	if (c >= 2048 && MB_CUR_MAX < 3)
		e->error = 1;
	if (c >= 65536 && MB_CUR_MAX < 4)
		e->error = 1;
}

static int		wcharlen(wchar_t c)
{	
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}

char			*ft_getwchar(wchar_t c, t_spe *e)
{
	char	*ret;
	
	check_mbcurmax(c, e);
	if ((ret = malloc(5)) == NULL)
		return (NULL);
	ft_bzero(ret, 5);
	if (c <= 127)
		ret[0] = c;
	else if (c <= 2047)
	{
		ret[0] = (((c >> 6) & 31) + 192);
		ret[1] = ((c & 63) + 128);
	}
	else if (c <= 65535)
	{
		ret[0] = (((c >> 12) & 15) + 224);
		ret[1] = (((c >> 6) & 63) + 128);
		ret[2] = ((c & 63) + 128);
	}
	else
	{
		ret[0] = (((c >> 18) & 7) + 240);
		ret[1] = (((c >> 12) & 63) + 128);	
		ret[2] = (((c >> 6) & 63) + 128);	
		ret[3] = ((c & 63) + 128);	
	}
	return (ret);
}

char			*ft_getwstr(wchar_t *str, t_spe *e)
{
	char	 	*ret;
	char		*wc;
	int				i;
	int				j;
	
	i = 0;
	if ((ret = malloc(ft_strlen((char *)str) * 4 + 1)) == NULL)
		return (NULL);
	while (*str)
	{
		if (e->precision > -1 && wcharlen(*str) + i > e->precision)
		{
			if (e->precision - i > 0)
				check_mbcurmax(*str, e);
			break ;
		}
		check_mbcurmax(*str, e);
		j = 0;
		if ((wc = ft_getwchar(*str, e)) == NULL)
			return (NULL);
		while (wc && wc[j])
			ret[i++] = wc[j++];
		free(wc);
		str++;
	}
	ret[i] = '\0';
	return (ret);
}
