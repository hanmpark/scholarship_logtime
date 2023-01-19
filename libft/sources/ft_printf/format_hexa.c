/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:36:47 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:28 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	count_hexa(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

static int	count_hexap(unsigned long long nbr)
{
	int	count;

	count = 1;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

char	*format_hexa(const char *hexadecimal, unsigned int nbr)
{
	int		count;
	char	*str;

	count = count_hexa(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

char	*format_pointer(const char *hexadecimal, unsigned long long nbr)
{
	int		count;
	char	*str;

	count = count_hexap(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	return (str);
}
