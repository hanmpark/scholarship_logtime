/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:07:28 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/18 18:08:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
/*\*/
char	*get_day(int month, int lastmonth, int fd)
{
	char	*str;
	char	*str_month;
	char	*str_day;
	
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	str_month = month_is(str);
	while (atoi(str_month) != month)
	{
		if (atoi(str_month) == lastmonth)
			break ;
		free(str);
		free(str_month);
		str = get_next_line(fd);
		if (!str)
			return(NULL);
		str_month = month_is(str);
	}
	str_day = day_is(str);
	while (atoi(str_month) == month && atoi(str_day) > 26)
	{
		free(str);
		free(str_day);
		str = get_next_line(fd);
		str_day = day_is(str);
	}
	if (atoi(str_month) < lastmonth || (atoi(str_month) == lastmonth && atoi(str_day) < 27))
		return (NULL);
	free(str_month);
	free(str_day);
	return (str);
}

void	get_month(char **str, int month, int lastmonth, int fd)
{
	int		i = 0;
	char	*str_month = month_is(str[i]);
	char	*str_day = day_is(str[i]);

	while (str[i] && atoi(str_month) == month && atoi(str_day) < 27)
	{
		str[++i] = get_next_line(fd);
		if (!str[i])
			break;
		free(str_month);
		free(str_day);
		str_month = month_is(str[i]);
		str_day = day_is(str[i]);
	}
	while (str[i] && atoi(str_month) == lastmonth && atoi(str_day) > 26)
	{
		str[++i] = get_next_line(fd);
		if (!str[i])
			break;
		free(str_month);
		free(str_day);
		str_month = month_is(str[i]);
		str_day = day_is(str[i]);
	}
	free(str[i]);
	str[i] = 0;
	free(str_month);
	free(str_day);
}
/**/