/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:21 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	def_specifier(t_parseflags *tab, const char *format, int *i)
{
	char				format_specifier;
	int					k;
	static t_printer	printer_tab[] = {
	{'s', &print_str}, {'c', &print_c}, {'d', &print_decimal},
	{'i', &print_decimal}, {'u', &print_unsigned}, {'x', &print_x},
	{'X', &print_xx}, {'p', &print_p}, {'%', &prct_wflags}
	};

	(*i)++;
	def_flags(tab, format, i);
	format_specifier = format[*i];
	k = -1;
	while (++k < 9)
	{
		if (format_specifier == printer_tab[k].c)
			printer_tab[k].ft(tab);
	}
}

int	ft_printf(const char *format, ...)
{
	t_parseflags	*tab;
	int				i;
	int				len;

	tab = malloc(sizeof(t_parseflags));
	if (!tab)
		return (-1);
	tab->len = 0;
	va_start(tab->args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			def_specifier(tab, format, &i);
		else if (format[i] && format[i] != '%')
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	len += tab->len;
	free(tab);
	return (len);
}
