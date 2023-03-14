/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:00:50 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:09:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include <unistd.h>

/* ------- colors / sets ------- */
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

void	print_bnlog(int *stdlog, int *bnlog);
void	print_holidays(char **holidays, int *stdlog, int show);
void	print_result(t_data *data);
int		set_month(char *month);
void	check_logtime(int month, int *stdlog, int *ttlog);

#endif