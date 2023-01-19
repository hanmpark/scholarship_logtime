/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:33:23 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:25:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define TRUE 1
# define FALSE 0

typedef struct s_parseflags
{
	va_list	args;
	int		len;
	int		check_width;
	int		check_precision;
	char	check_nbrflags;
	char	check_zerojustify;
	int		width;
	int		precision;
}	t_parseflags;

typedef void	(*t_ftprinter)(t_parseflags *);
typedef struct s_printer
{
	char		c;
	t_ftprinter	ft;
}	t_printer;

int		ft_printf(const char *format, ...);

/* PRINT */
void	print_str(t_parseflags *tab);
void	print_c(t_parseflags *tab);
void	print_decimal(t_parseflags *tab);
void	print_unsigned(t_parseflags *tab);
void	print_x(t_parseflags *tab);
void	print_xx(t_parseflags *tab);
void	print_p(t_parseflags *tab);

/* FORMAT HEXADECIMAL */
char	*format_hexa(const char *hexadecimal, unsigned int nbr);
char	*format_pointer(const char *hexadecimal, unsigned long long nbr);

/* FLAGS */
void	def_flags(t_parseflags *tab, const char *format, int *i);
/* SPECIFIER FILTERS FOR FLAGS */
void	c_wflags(t_parseflags *tab, int c);
void	str_wflags(t_parseflags *tab, char *str, int len);
void	nbr_wflags(t_parseflags *tab, char *str, int sign, int len);
void	prct_wflags(t_parseflags *tab);

/* TREAT_FLAGS */
void	widthstr(t_parseflags *tab, char *str, int len);
void	widthc(t_parseflags *tab, char c);
void	widthnbr(t_parseflags *tab, char *str, int sign, int len);
void	left_justifyc(t_parseflags *tab, char c);
void	left_justifystr(t_parseflags *tab, char *str, int len);
void	left_justifynbr(t_parseflags *tab, char *str, int sign, int len);
void	pad_zero(t_parseflags *tab, char *str, int sign, int len);
void	treat_nbrflags(t_parseflags *tab, int sign);

#endif