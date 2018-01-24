/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:03 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/24 17:45:14 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_mbcurmax(wchar_t c, t_spe *e)
{
	if (c < 0)
		e->error = 1;
	if (c >= 256 && MB_CUR_MAX < 2)
		e->error = 1;
	if (c >= 2048 && MB_CUR_MAX < 3)
		e->error = 1;
	if (c >= 65536 && MB_CUR_MAX < 4)
		e->error = 1;
	if (c > 1114111 || (c > 55295 && c < 57344))
		e->error = 1;
	return (0);
}

static int	wcharlen(wchar_t c)
{
	if (c <= 255)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}

static char	*ft_getwchar2(wchar_t c, char *ret)
{
	if (c <= 65535 && MB_CUR_MAX > 2)
	{
		ret[0] = (((c >> 12) & 15) + 224);
		ret[1] = (((c >> 6) & 63) + 128);
		ret[2] = ((c & 63) + 128);
	}
	else if (c > 65535 && MB_CUR_MAX > 3)
	{
		ret[0] = (((c >> 18) & 7) + 240);
		ret[1] = (((c >> 12) & 63) + 128);
		ret[2] = (((c >> 6) & 63) + 128);
		ret[3] = ((c & 63) + 128);
	}
	return (ret);
}

char		*ft_getwchar(wchar_t c, t_spe *e)
{
	char	*ret;

	check_mbcurmax(c, e);
	if ((ret = malloc(5)) == NULL)
		return (NULL);
	ft_bzero(ret, 5);
	if (c <= 127 || (c < 255 && MB_CUR_MAX < 2))
		ret[0] = c;
	else if (c <= 2047 && MB_CUR_MAX > 1)
	{
		ret[0] = (((c >> 6) & 31) + 192);
		ret[1] = ((c & 63) + 128);
	}
	else
		ret = ft_getwchar2(c, ret);
	return (ret);
}

char		*ft_getwstr(wchar_t *str, t_spe *e)
{
	char	*ret;
	char	*wc;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(ft_strlen((char *)str) * 4 + 1);
	while (*str)
	{
		if (e->precision > -1 && wcharlen(str[0]) + i > e->precision)
			break ;
		check_mbcurmax(str[0], e);
		j = 0;
		wc = ft_getwchar(str[0], e);
		while (wc && wc[j])
			ret[i++] = wc[j++];
		free(wc);
		str++;
	}
	ret[i] = '\0';
	return (ret);
}
