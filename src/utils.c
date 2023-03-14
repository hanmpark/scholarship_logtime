/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:18:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include <unistd.h>

void	free_month(char **date)
{
	int	i;

	i = 0;
	while (i < 32)
		free(date[i++]);
	free(date);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	count_len(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len++;
	while (n / nbr && n != 0)
	{
		nbr *= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	long	nbr;

	i = count_len(n);
	nbr = n;
	a = malloc((i + 1) * sizeof(char));
	if (!a)
		return (0);
	if (nbr < 0)
	{
		a[0] = '-';
		nbr *= -1;
	}
	a[i] = 0;
	while (i-- > 0)
	{
		if (i == 0 && nbr % 10 == 0 && n < 0)
			break ;
		a[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (a);
}
