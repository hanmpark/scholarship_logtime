/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:16:15 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_x(t_parseflags *tab)
{
	unsigned int	nbr;
	char			*str;
	int				len;

	nbr = va_arg(tab->args, unsigned);
	str = format_hexa("0123456789abcdef", nbr);
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (tab->check_nbrflags == '#' && nbr != 0)
	{
		tab->check_nbrflags = '0';
		len += 2;
	}
	else if (tab->check_nbrflags == '#' && nbr == 0)
		tab->check_nbrflags = 0;
	nbr_wflags(tab, str, FALSE, len);
	free(str);
}

void	print_xx(t_parseflags *tab)
{
	unsigned int	nbr;
	char			*str;
	int				len;

	nbr = va_arg(tab->args, unsigned);
	str = format_hexa("0123456789ABCDEF", nbr);
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (tab->check_nbrflags == '#' && nbr != 0)
	{
		tab->check_nbrflags = '1';
		len += 2;
	}
	else if (tab->check_nbrflags == '#' && nbr == 0)
		tab->check_nbrflags = 0;
	nbr_wflags(tab, str, FALSE, len);
	free(str);
}

void	print_p(t_parseflags *tab)
{
	unsigned long long	nbr;
	char				*str;
	int					len;

	nbr = va_arg(tab->args, unsigned long long);
	str = format_pointer("0123456789abcdef", nbr);
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
	{
		tab->len += write(1, "0x", 2);
		return ;
	}
	else
		len = (int)ft_strlen(str);
	tab->check_nbrflags = '0';
	len += 2;
	nbr_wflags(tab, str, FALSE, len);
	free(str);
}
