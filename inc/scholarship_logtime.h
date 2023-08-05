/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/06 01:13:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOLARSHIP_LOGTIME_H
# define SCHOLARSHIP_LOGTIME_H

# include <stdlib.h>
# include <stdbool.h>

# define GET_LAST_MONTH(month) (month == 1 ? 12 : month - 1)
# define GET_LAST_YEAR(month, year) (month == 1 ? year - 1 : year)

typedef struct s_logtime
{
	int	*log;
	int	*bn_log;
	int	hd_log;
	int	bnhd_log;
	int *total_log;
	int	*time_left;
	int	*avg_left;
	int	dleft;
}	t_logtime;

typedef struct s_data
{
	char				**chosen;
	char				**bonus;
	char				**holidays;
	char				**bonus_holidays;
	struct s_logtime	*log;
	int					month;
	int					last_month;
	bool				show;
}	t_data;

void	init_data(char **argv, t_data *data);
void	free_structure(t_data data);
void	free_array(char **array);

#endif
