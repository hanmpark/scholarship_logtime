/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/23 17:01:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

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

static int	animated_bar(char *color, int prct, int printprct)
{
	int		i;
	char	*prctstr;

	i = 0;
	printf("[");
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%", color, prct);
	prctstr = ft_itoa(prct);
	i += (int)strlen(prctstr) + 2;
	free(prctstr);
	while (i--)
		printf("\b");
	while (i++ < printprct && i < 31)
	{
		printf("%s▰%s", color, DEF);
		usleep(50000);
	}
	return (i);
}

void	print_progress(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	i = 0;
	prct = 100 * tthours / hours;
	printprct = 31 * prct / 100;
	if (prct < 26)
		color = RED;
	else if (prct < 76)
		color = YELLOW;
	else
		color = GREEN;
	i = animated_bar(color, prct, printprct);
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%%s\n\n", color, prct, DEF);
}
