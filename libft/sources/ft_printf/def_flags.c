/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	init_flags(t_parseflags *tab)
{
	tab->check_width = 0;
	tab->check_precision = 0;
	tab->check_nbrflags = 0;
	tab->check_zerojustify = 0;
	tab->width = 0;
	tab->precision = 0;
}

static void	parse_width(t_parseflags *tab, const char *format, int *i)
{
	if (format[*i] && ft_isdigit(format[*i]))
	{
		tab->check_width = TRUE;
		tab->width = ft_atoi(format + *i);
	}
	while (format[*i] && (ft_isdigit(format[*i])))
		(*i)++;
}

static void	parse_precision(t_parseflags *tab, const char *format, int *i)
{
	if (format[*i] && format[*i] == '.')
	{
		tab->check_precision = TRUE;
		(*i)++;
		if (format[*i] && ft_isdigit(format[*i]))
			tab->precision = ft_atoi(format + *i);
		while (format[*i] && ft_isdigit(format[*i]))
			(*i)++;
	}
}

static void	parse_flags(t_parseflags *tab, const char *format, int *i)
{
	while (format[*i] && (format[*i] == '#' || format[*i] == ' '
			|| format[*i] == '+'))
	{
		tab->check_nbrflags = format[*i];
		(*i)++;
	}
	while (format[*i] && (format[*i] == '-' || format[*i] == '0'))
	{
		if (tab->check_zerojustify != '-')
			tab->check_zerojustify = format[*i];
		(*i)++;
	}
	while (format[*i] && (format[*i] == '#' || format[*i] == ' '
			|| format[*i] == '+'))
	{
		tab->check_nbrflags = format[*i];
		(*i)++;
	}
}

void	def_flags(t_parseflags *tab, const char *format, int *i)
{
	init_flags(tab);
	parse_flags(tab, format, i);
	parse_width(tab, format, i);
	parse_precision(tab, format, i);
}
