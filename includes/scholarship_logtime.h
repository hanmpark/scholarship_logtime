/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scholarship_logtime.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:56:48 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 03:23:43 by hanmpark         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

/* colors / sets */
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

/* GET_NEXT_LINE */
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	ft_freeall(char *buf, char *line, char *stash);
void	*ft_calloc(size_t count, size_t size);
char	*ft_bufferjoin(char *s1, char *s2);
char	*ft_linetrim(char *str);

/* LOGTIME */
void	parse_data(void);
void	parse_holidays(void);
char	**ft_split(const char *s, char c);
int		trim_tab(char **tab, int len);
void	free_date(char **date);
void	print_progress(int tthours, int hours);
void	ft_putstr_fd(char *str, int fd);
void	parse_calculation(int month, int lastmonth, char **date, char **bonus_date);
void	check_logtime(int month, int *stdlog, int *ttlog);
char	**parse_month(int month, int lastmonth, int fd);
int		days_left(void);
int		current_month(void);
int		current_day(void);
int		current_year(void);

#endif
