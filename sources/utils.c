/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/18 17:12:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
/*\*/
// TELLS WHAT THE MONTH IS
char	*month_is(char *src)
{
	char	*dest;
	int		i = 0;
	int		j = 5;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

// TELLS WHAT THE DAY IS
char	*day_is(char *src)
{
	char	*dest;
	int		i = 0;
	int		j = 8;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

// CLEAR DATE
void	free_date(char **date)
{
	int	i = 0;

	while (date[i])
		free(date[i++]);
	free(date);
}

// CALCULATES THE TIME LEFT
void	ccl_timeleft(int *ttlog)
{
	if (ttlog[0] > 0)
		{
			ttlog[0] = 60 - ttlog[0];
			ttlog[1]++;
		}
	if (ttlog[1] > 0)
	{
		ttlog[1] = 60 - ttlog[1];
		ttlog[2]++;
	}
}
/**/