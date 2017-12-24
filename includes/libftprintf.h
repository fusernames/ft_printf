/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:25:58 by alcaroff          #+#    #+#             */
/*   Updated: 2017/12/24 14:52:40 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

typedef struct	s_spe
{
	char				spe;
	char				conv[3];
	int					zero;
	int					hash;
	int					space;
	int					plus;
	int					minus;
	int				error;
	long long int			width;
	long long int			precision;
	char				*s;
	struct s_spe		*next;
}				t_spe;

int				ft_printf(const char *format, ...);
int				parser(char *fmt, va_list *ap, t_spe **start);
int				parse_str(t_spe *start, va_list ap);
int				check_exceptions(t_spe *start);
int				crave(t_spe *start);
int				lst_del(t_spe *start);
t_spe			*init_elem(void);
int				print_specifier(t_spe *e);

int				is_specifier(int c);
int				is_flag(int c);

char			*ft_itoa_base(long long n, int base);
char			*ft_itoa_base_un(unsigned long long n, int base);
char			*ft_getwstr(wchar_t *str, t_spe *e);
char			*ft_getwchar(wchar_t c, t_spe *e);

int				ft_atoi(const char *s);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, int n);
size_t			ft_strlen(const char *s);
char			*ft_strtolower(char *str);
char			*ft_getchar(char c);
int				ft_strisspace(const char *str);
int				ft_putstr(const char *s);
int				ft_putchar(int c);

#endif
