/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 15:17:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOLARSHIP_LOGTIME_H
# define SCHOLARSHIP_LOGTIME_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

/* ------- colors / sets ------- */
# define DEF "\033[0m"
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UL "\033[4m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define GRAY "\033[2;37m"

/* ------- GET_NEXT_LINE ------- */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	ft_freeall(char *buf, char *line, char *stash);
void	*ft_calloc(size_t count, size_t size);
char	*ft_bufferjoin(char *s1, char *s2);
char	*ft_linetrim(char *str);

/* ---------- LOGTIME ---------- */
/* parse api */
void	api_dates(void);
void	api_public_holidays(void);
int		trim_tab(char **tab, int len);
char	**ft_split(const char *s, char c);
void	free_holidays(char **tab);

/* utils */
void	free_month(char **date);
void	print_progress(int tthours, int hours);
void	ft_putstr_fd(char *str, int fd);

/* set logtime */
void	ccl_logtime(int month, int lastmonth, char **date, char **bonus_date);
void	check_logtime(int month, int *stdlog, int *ttlog);

/* find month */
char	**parse_month(int month, int lastmonth, int fd);

/* current time */
int		days_left(void);
int		current_month(void);
int		current_day(void);
int		current_year(void);
void	set_holidays(int month, int lastmonth, int *stdlog, int *bnlog);

#endif
