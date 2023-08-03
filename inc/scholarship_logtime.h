/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/03 21:45:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOLARSHIP_LOGTIME_H
# define SCHOLARSHIP_LOGTIME_H

# include <stdlib.h>
# include <stdbool.h>

# define HOLIDAYS 1
# define DATES 0

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
