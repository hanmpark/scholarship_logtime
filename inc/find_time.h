/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_time.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:05:09 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:13:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_TIME_H
# define FIND_TIME_H

# include <time.h>

int		days_left(void);
int		current_month(void);
int		current_day(void);
int		current_year(void);
void	set_holidays(t_data *data, int *stdlog, int *bnlog);

#endif