/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:03:05 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	str_wflags(t_parseflags *tab, char *str, int len)
{
	if (tab->check_precision == TRUE && tab->precision < len)
		len = tab->precision;
	if (tab->check_zerojustify == '-')
		left_justifystr(tab, str, len);
	else
		widthstr(tab, str, len);
}

void	c_wflags(t_parseflags *tab, int c)
{
	if (tab->check_zerojustify == '-')
		left_justifyc(tab, c);
	else
		widthc(tab, c);
}

void	prct_wflags(t_parseflags *tab)
{
	int	c;

	c = '%';
	if (tab->check_zerojustify == '-')
		left_justifyc(tab, c);
	else if (tab->check_zerojustify == '0')
		pad_zero(tab, "%", 2, 1);
	else
		widthc(tab, c);
}

void	nbr_wflags(t_parseflags *tab, char *str, int sign, int len)
{
	if (tab->check_zerojustify == '0' && tab->check_precision == FALSE)
		pad_zero(tab, str, sign, len);
	else if (tab->check_zerojustify == '-')
		left_justifynbr(tab, str, sign, len);
	else
		widthnbr(tab, str, sign, len);
}

void	treat_nbrflags(t_parseflags *tab, int sign)
{
	if (sign == FALSE && tab->check_nbrflags == '+')
		write(1, "+", 1);
	else if (sign == FALSE && tab->check_nbrflags == ' ')
		write(1, " ", 1);
	else if (sign == FALSE && tab->check_nbrflags == '0')
		write(1, "0x", 2);
	else if (sign == FALSE && tab->check_nbrflags == '1')
		write(1, "0X", 2);
	else if (sign == TRUE)
		write(1, "-", 1);
}
