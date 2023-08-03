/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:05:09 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/03 21:41:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIME_H
# define GET_TIME_H

# define TXT_MONTH 5
# define TXT_DAY 8
# define TXT_SECONDS 19
# define TXT_MINUTES 16
# define TXT_HOURS 13

# define H 2
# define MIN 1
# define S 0

# include <time.h>

void		set_dates(t_data *data);
int			days_left(void);
int			current_month(void);
int			current_day(void);
int			current_year(void);

t_logtime	*get_logs(t_data data);
int			find_time(char *src, int time_type);
int			*ccl_addlog(char **date);
int			*ccl_total_logtime(int *stdlog, int *bnlog);
int			*ccl_timeleft(int *ttlog);
int			ccl_hdlog(char **holidays);
int			*ccl_avgleft(int *dleft, int *time_left);
bool		cut_max_log(int *logtime);

#endif