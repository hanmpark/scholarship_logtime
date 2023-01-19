/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_str(t_parseflags *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		str_wflags(tab, "(null)", 6);
		return ;
	}
	len = (int)ft_strlen(str);
	str_wflags(tab, str, len);
}

void	print_c(t_parseflags *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	c_wflags(tab, c);
}

void	print_decimal(t_parseflags *tab)
{
	long	nbr;
	int		sign;
	int		len;
	char	*str;

	nbr = va_arg(tab->args, int);
	sign = FALSE;
	if (nbr < 0)
	{
		sign = TRUE;
		nbr *= -1;
	}
	str = ft_itoa(nbr);
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (sign == TRUE || (sign == FALSE && tab->check_nbrflags))
		len++;
	nbr_wflags(tab, str, sign, len);
	free(str);
}

void	print_unsigned(t_parseflags *tab)
{
	unsigned int	nbr;
	char			*str;
	int				len;

	nbr = va_arg(tab->args, unsigned);
	str = ft_itoa(nbr);
	if (nbr == 0 && tab->check_precision == TRUE && tab->precision == 0)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (tab->check_nbrflags)
		len++;
	nbr_wflags(tab, str, FALSE, len);
	free(str);
}
