/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/23 17:01:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOLARSHIP_LOGTIME_H
# define SCHOLARSHIP_LOGTIME_H
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>

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

/* ---------- LOGTIME ---------- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* get_next_line */
char	*get_next_line(int fd);
void	ft_freeall(char *buf, char *line, char *stash);
char	*ft_bufferjoin(char *s1, char *s2);
char	*ft_linetrim(char *str);

/* parse api */
void	api_dates(void);
void	api_public_holidays(void);
void	free_holidays(char **tab);
int		trim_tab(char **tab, int len);
char	**ft_split(char const *s, char c);

/* utils */
void	free_month(char **date);
void	print_progress(int tthours, int hours);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

/* set logtime */
void	ccl_logtime(int month, int lastmonth, char **date, char **bonus_date, int show);
void	check_logtime(int month, int *stdlog, int *ttlog);

/* find month */
char	**parse_month(int month, int lastmonth, int fd);

/* current time */
int		days_left(void);
int		current_month(void);
int		current_day(void);
int		current_year(void);
void	set_holidays(int month, int lastmonth, int *stdlog, int *bnlog, int show);

#endif
