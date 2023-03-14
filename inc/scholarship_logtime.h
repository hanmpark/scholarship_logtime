/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:16:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOLARSHIP_LOGTIME_H
# define SCHOLARSHIP_LOGTIME_H

# include <stdlib.h>

# define HOLIDAYS 1
# define DATES 0

typedef struct s_data
{
	char	**chosen;
	char	**bonus;
	int		month;
	int		last_month;
	int		show_dates;
}	t_data;

/* utils */
void	free_month(char **date);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

#endif
