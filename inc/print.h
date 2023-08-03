/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:00:50 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/04 00:00:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include <unistd.h>

/* ------- COLORS / SETS ------- */

# define DEF "\033[0m"
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UL "\033[4m"
# define BACK "\033[0K\r"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define GRAY "\033[2;37m"

/* ------- PRINTS MESSAGES ------- */

# define PRINT_MONTH BLUE "\nTHE CHOSEN MONTH'S LOGTIMES:\n" DEF
# define PRINT_HD BLUE "\nPUBLIC HOLIDAYS:\n" DEF
# define PRINT_HD_HOURS ITALIC GREEN "  +%dh\n" DEF
# define PRINT_BNLOG BOLD "\nBonus log: " GREEN "%dh %dmin %ds\n\n" DEF
# define PRINT_WITHOUT_BN CYAN "Without bonus = " UL "%dh %dmin %ds" DEF

# define PRINT_TOTAL_TIME CYAN BOLD "\nTotal logtime = " UL "%dh %dmin %ds\n\n" DEF
# define PRINT_ASK_DAYSOFF ITALIC GRAY "The number of days you want to take off from now on: " DEF GREEN
# define PRINT_INCOMPATIBLE_DAYSOFF ITALIC RED "\t\tIncompatible days off\n" DEF
# define PRINT_DAYSOFF DEF BOLD "Days off : " GREEN "%d\n" DEF
# define PRINT_TIME_LEFT BOLD "Time left: " GREEN "%dh %dmin %ds\n" DEF
# define PRINT_DAYS_LEFT BOLD "Days left: " GREEN "%d days\n" DEF
# define PRINT_TO_DO BOLD "To do log: %s%dh %dmin %ds / day\n" DEF 
# define PRINT_NEXT_BONUS PURPLE "Next month bonus: " GREEN "%dh %dmin %ds\n" DEF

# define LOGTIME_OK GREEN ITALIC "\t\t     LOGTIME OK !\n\n" DEF
# define NOTHING PURPLE "\t\tNothing for next month\n" DEF

void	print_logtime(t_data data);
void	check_logtime(t_logtime *log);
void	print_progressbar(int tthours, int hours);

#endif