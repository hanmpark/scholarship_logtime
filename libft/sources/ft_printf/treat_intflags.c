/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_intflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:33:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	precision_count(t_parseflags *tab, int len)
{
	int	toprint;

	toprint = tab->precision - len;
	if (toprint < 0)
		toprint = 0;
	return (toprint);
}

static void	precision_nbr(t_parseflags *tab, int sign, int precisionlen)
{
	if (precisionlen > 0)
		treat_nbrflags(tab, sign);
	while (precisionlen-- > 0)
		write(1, "0", 1);
}

void	pad_zero(t_parseflags *tab, char *str, int sign, int len)
{
	int		toprint;

	toprint = tab->width - len;
	treat_nbrflags(tab, sign);
	while (toprint-- > 0)
		tab->len += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	tab->len += len;
}

void	left_justifynbr(t_parseflags *tab, char *str, int sign, int len)
{
	int	toprint;
	int	precisionpad;

	precisionpad = precision_count(tab, (int)ft_strlen(str));
	precision_nbr(tab, sign, precisionpad);
	if (precisionpad == 0)
		treat_nbrflags(tab, sign);
	if (!(len == 1 && tab->check_nbrflags) && len > 0)
		ft_putstr_fd(str, 1);
	tab->len += len + precisionpad;
	toprint = tab->width - (len + precisionpad);
	while (toprint-- > 0)
		tab->len += write(1, " ", 1);
}

void	widthnbr(t_parseflags *tab, char *str, int sign, int len)
{
	int	toprint;
	int	precisionpad;

	precisionpad = precision_count(tab, (int)ft_strlen(str));
	toprint = tab->width - (len + precisionpad);
	while (toprint-- > 0)
		tab->len += write(1, " ", 1);
	precision_nbr(tab, sign, precisionpad);
	if (precisionpad == 0)
		treat_nbrflags(tab, sign);
	if (!(len == 1 && tab->check_nbrflags) && len > 0)
		ft_putstr_fd(str, 1);
	tab->len += len + precisionpad;
}
