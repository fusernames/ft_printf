/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:25:58 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/07 19:21:44 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <wchar.h>
# include "libft.h"

# define LLONG_MIN 9223372036854775807

typedef struct	s_spe
{
	char				specifier;
	char				conv[3];
	int					zero;
	int					hash;
	int					space;
	int					plus;
	int					less;
	int					width;
	int					precision;
	unsigned char			*s;
	struct s_spe		*next;
}				t_spe;

int				ft_printf(const char *format, ...);
int				parser(const char *format, t_spe **start);
int				check_exceptions(t_spe *start);
int				get_str(va_list ap, t_spe *start);

int				is_specifier(int c);
char			*itoa_base(long long n, int base);
char			*itoa_base_un(unsigned long long n, int base);

unsigned char		*ft_getwstr(wchar_t *str);
unsigned char		*ft_getwchar(wchar_t c);

#endif
