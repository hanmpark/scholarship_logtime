/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:20:20 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 18:37:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
#include <time.h>

int	day_left(void)
{
	time_t		t;
	struct tm	*timeinfo;
	
	time(&t);
	timeinfo = localtime(&t);
	return (26 - timeinfo->tm_mday);
}

int	current_month(void)
{
	time_t		t;
	struct tm	*timeinfo;
	
	time(&t);
	timeinfo = localtime(&t);
	return (timeinfo->tm_mon+1);
}